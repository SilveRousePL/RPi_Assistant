//
// Created by darek on 26.01.18.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>

namespace Misc {
    std::string currentTime(std::string param="%T") {
        //auto now = chrono::system_clock::now();
        time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::ostringstream oss;
        //oss << std::put_time(std::localtime(&now_c), param.c_str());
        return oss.str();
    }
}
