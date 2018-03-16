//
// Created by darek on 27.01.18.
//

#pragma once
#include "CSCommonPart.hpp"

class Client : public CSCommonPart {
    /// Server IP address.
    std::string server_ip;
    /// Server port number.
    uint16_t server_port;

public:
    /*!
     * Create client.
     * @param server_ip Server IP address.
     * @param server_port Server port.
     * @throw SocketException If problem with connection.
     */
    Client(std::string server_ip, uint16_t server_port);
    virtual ~Client();

    /*!
     * Method sends data to server.
     * @param message Text string to send.
     * @return 0 - Success; Other value - Error.
     */
    int32_t sendPacket(std::string message);
};
