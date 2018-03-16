//
// Created by darek on 27.01.18.
//

#pragma once
#include "CSCommonPart.hpp"

class Server : public CSCommonPart {
    /// Server port number.
    uint16_t server_port;
    /// Client's IP address who last sent the packet.
    std::string last_client_ip;
    /// Client's port number who last sent the packet.
    uint16_t last_client_port;

public:
    /*!
     * Create server.
     * @param port Server port.
     * @throw SocketException If port number is busy.
     */
    Server(uint16_t port);
    virtual ~Server();

    /*!
     * Method read packet from queue without remove it and set last receiver data.
     * @return Packet from queue.
     */
    Packet readPacket();
    /*!
     * Method read packet from queue, remove it and set last receiver data.
     * @return Packet from queue.
     */
    Packet popPacket();

    /*!
     * Getter: Client's IP address who last sent the packet.
     * @return Last IP address.
     */
    std::string getLastClientIP();
    /*!
     * Getter: Client's port number who last sent the packet.
     * @return Last port number.
     */
    uint16_t getLastClientPort();
};
