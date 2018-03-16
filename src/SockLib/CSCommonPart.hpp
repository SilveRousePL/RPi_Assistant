//
// Created by darek on 04.03.18.
//

#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <exception>
#include <queue>
#include "NetSock.h"
#include "Packet.hpp"
#include "Exceptions.hpp"

class CSCommonPart {
protected:
    std::thread * thread;
    /// Socket from NetSock library.
    NetSock * socket;
    /// Char buffer to read data.
    size_t buffer_size;
    /// Packet queue.
    std::queue<Packet> packets;

    std::mutex mtx;
    std::exception_ptr excpt;

public:
    CSCommonPart();
    ~CSCommonPart();
    /*!
     * Method check are there any packets in queue.
     * @return True if exists, false in the second case.
     */
    bool isAnyPacket();
    /*!
     * Method read packet from queue without remove it.
     * @return Packet from queue.
     */
    Packet readPacket();
    /*!
     * Method read packet from queue and remove it.
     * @return Packet from queue.
     */
    Packet popPacket();
    /*!
     * Method sends data to client or other server.
     * @param message Text string to send.
     * @param host IP address receiver.
     * @param port Receiver port.
     * @return 0 - Success; Other value - Error.
     */
    int32_t sendPacket(std::string message, std::string host, uint16_t port);
    /// Method runs in a separate thread
    void run();

protected:
    /// Method receive packet from remote host.
    void receivePacket();
    /*!
     * Method adds packet to queue.
     * @param packet Packet to add.
     */
    void pushPacket(Packet packet);

};