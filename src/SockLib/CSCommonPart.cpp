//
// Created by darek on 04.03.18.
//

#include "CSCommonPart.hpp"
#include "Misc.hpp"

CSCommonPart::CSCommonPart() : thread(nullptr), socket(new NetSock), buffer_size(512) {}

CSCommonPart::~CSCommonPart() {
    mtx.unlock();
    if(socket != nullptr) {
        socket->Disconnect();
        delete socket;
    }
    if (thread != nullptr) {
        thread->join();
        delete thread;
    }
}

void CSCommonPart::run() {
    while(true) {
        receivePacket();
        try {
        } catch (Exception &e) {
            this->excpt = std::current_exception();
            std::cerr << e.what() << std::endl;
        } catch (...) {
            this->excpt = std::current_exception();
            std::cerr << "Unknown exception" << std::endl;
        }
    }
}

bool CSCommonPart::isAnyPacket() {
    return !packets.empty();
}

Packet CSCommonPart::readPacket() {
    if(packets.empty()) return Packet();
    this->mtx.lock();
    Packet p = packets.front();
    this->mtx.unlock();
    return p;
}

void CSCommonPart::pushPacket(Packet packet) {
    if(packets.size() >= 1024) return; // Ograniczenie ilości elementów
    this->mtx.lock();
    packets.push(packet);
    this->mtx.unlock();
}

Packet CSCommonPart::popPacket() {
    if(packets.empty()) return Packet();
    this->mtx.lock();
    Packet p = packets.front();
    packets.pop();
    this->mtx.unlock();
    return p;
}

int32_t CSCommonPart::sendPacket(std::string message, std::string host, uint16_t port) {
    message += "\n";
    int ret = socket->WriteUDP(host.c_str(), port, message.c_str(), message.length());
    return ret - message.length();
}

void CSCommonPart::receivePacket() {
    char srcHost[16] = {0};
    uint16_t srcPort = 0;
    std::string buffer_str;
    char * buffer = new char[buffer_size];

    int p_size = socket->ReadUDP(buffer, buffer_size, srcHost, &srcPort);
    if(buffer[p_size-1] == '\n') buffer[p_size-1] = 0;
    buffer_str = buffer;
    delete [] buffer;

    if(p_size <= 0) {
        std::cerr << "Błąd odczytu!" << std::endl;
        return;
    }

    pushPacket(Packet(srcHost, srcPort, Misc::currentTime(), buffer_str));
}