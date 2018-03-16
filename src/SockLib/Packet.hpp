//
// Created by darek on 26.02.18.
//

#pragma once
#include <string>
#include <ostream>


class Packet {
public:
    std::string host;
    uint16_t port;
    std::string time;
    std::string data;

    Packet(std::string host="", uint16_t port=0, std::string time="", std::string data="")
            : host(host), port(port), time(time), data(data) {}
    ~Packet() {}

    friend std::ostream& operator<<(std::ostream & ostr, const Packet & obj) {
        ostr << obj.host << ":" << obj.port << " " << obj.time << ": " << obj.data;
        return ostr;
    }

    /*std::ostream& operator<<(std::ostream &ostr, const Item& obj) {
        ostr << obj.name << std::endl;
        return ostr;*/
};