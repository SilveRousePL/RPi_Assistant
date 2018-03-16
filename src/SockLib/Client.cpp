//
// Created by darek on 27.01.18.
//

#include "Client.hpp"

Client::Client(std::string server_ip, uint16_t server_port) : server_ip(server_ip), server_port(server_port) {
    if (!socket->ListenUDP(server_port, server_ip.c_str()))
        throw SocketException("Błąd połączenia z serwerem " + server_ip + "...");
    thread = new std::thread(&CSCommonPart::run, this);
}

Client::~Client() {}

int32_t Client::sendPacket(std::string message) {
    return CSCommonPart::sendPacket(message, this->server_ip, this->server_port);
}