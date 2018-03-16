/*
 * Buzzer.cpp
 *
 *  Created on: 12 mar 2018
 *      Author: darek
 */

#include "Buzzer.hpp"

Buzzer::Buzzer() {
	// TODO Auto-generated constructor stub
	if (softToneCreate(29) != 0) std::cout << "Problem" << std::endl;//throw Exception("Buzzer problem!");
			/*softToneWrite(29, 261);
			delay(700);
			softToneWrite(29, 293);
			delay(700);
			softToneWrite(29, 329);
			delay(700);
			softToneWrite(29, 349);
			delay(700);
			softToneWrite(29, 391);
			delay(1400);
			softToneWrite(29, 329);
			delay(1400);
			softToneWrite(29, 391);
			delay(1400);
			softToneWrite(29, 329);
			delay(1400);
			softToneWrite(29, 329);
			delay(700);
			softToneWrite(29, 293);
			delay(700);
			softToneWrite(29, 261);
			delay(700);
			softToneStop(1);*/

}

Buzzer::~Buzzer() {
	// TODO Auto-generated destructor stub
}

