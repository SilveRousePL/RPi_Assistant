/*
 * ExecutivePart.hpp
 *
 *  Created on: 12 mar 2018
 *      Author: darek
 */

#ifndef EXECUTIVEPART_HPP_
#define EXECUTIVEPART_HPP_

#include <iostream>
#include "SockLib/Server.hpp"
#include "SockLib/Client.hpp"
#include "HD44780.hpp"
#include "Buzzer.hpp"

class ExecutivePart {
	Server* server;
	HD44780* lcd;
	Buzzer* buzzer;

public:
	ExecutivePart();
	virtual ~ExecutivePart();

private:
    void run();
    void execute(std::string command);
};

#endif /* EXECUTIVEPART_HPP_ */
