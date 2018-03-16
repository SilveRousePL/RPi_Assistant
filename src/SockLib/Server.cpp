//
// Created by darek on 27.01.18.
//

#include "Server.hpp"

Server::Server(uint16_t port) : CSCommonPart(), server_port(port) {
    if (!socket->ListenAllUDP(server_port))
        throw SocketException("Błąd przy tworzeniu serwera, sprawdź czy inna aplikacja nie używa danego portu");
    thread = new std::thread(&CSCommonPart::run, this);
}

Server::~Server() {}

Packet Server::readPacket() {
    Packet p = CSCommonPart::readPacket();
    this->last_client_ip = p.host;
    this->last_client_port = p.port;
    return p;
}

Packet Server::popPacket() {
    Packet p = CSCommonPart::popPacket();
    this->last_client_ip = p.host;
    this->last_client_port = p.port;
    return p;
}

std::string Server::getLastClientIP() {
    return this->last_client_ip;
}

uint16_t Server::getLastClientPort() {
    return this->last_client_port;
}