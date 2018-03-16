//
// Created by darek on 18.02.2018.
//

#pragma once
#include <cstdint>
#include "../../@RPi_Tools@/wiringPi/wiringPi.h"

#define HD44780_RS_PIN				4
#define HD44780_E_PIN				5
#define HD44780_D4_PIN				26
#define HD44780_D5_PIN				27
#define HD44780_D6_PIN				28
#define HD44780_D7_PIN				29

#define HD44780_RS_LOW              digitalWrite(HD44780_RS_PIN, 0)
#define HD44780_RS_HIGH             digitalWrite(HD44780_RS_PIN, 1)
#define HD44780_E_LOW              	digitalWrite(HD44780_E_PIN, 0)
#define HD44780_E_HIGH              digitalWrite(HD44780_E_PIN, 1)

#define HD44780_E_BLINK             HD44780_E_HIGH; HD44780_Delay(50); HD44780_E_LOW; HD44780_Delay(50)
#define HD44780_Delay(x)            delayMicroseconds(x)

#define HD44780_CLEARDISPLAY        0x01
#define HD44780_RETURNHOME          0x02
#define HD44780_ENTRYMODESET        0x04
#define HD44780_DISPLAYCONTROL      0x08
#define HD44780_CURSORSHIFT         0x10
#define HD44780_FUNCTIONSET         0x20
#define HD44780_SETCGRAMADDR        0x40
#define HD44780_SETDDRAMADDR        0x80

#define HD44780_ENTRYRIGHT          0x00
#define HD44780_ENTRYLEFT           0x02
#define HD44780_ENTRYSHIFTINCREMENT 0x01
#define HD44780_ENTRYSHIFTDECREMENT 0x00

#define HD44780_DISPLAYON           0x04
#define HD44780_CURSORON            0x02
#define HD44780_BLINKON             0x01

#define HD44780_DISPLAYMOVE         0x08
#define HD44780_CURSORMOVE          0x00
#define HD44780_MOVERIGHT           0x04
#define HD44780_MOVELEFT            0x00

#define HD44780_8BITMODE            0x10
#define HD44780_4BITMODE            0x00
#define HD44780_2LINE               0x08
#define HD44780_1LINE               0x00
#define HD44780_5x10DOTS            0x04
#define HD44780_5x8DOTS             0x00

class HD44780 {
	uint8_t displayControl;
	uint8_t displayFunction;
	uint8_t displayMode;
	uint8_t cols;
	uint8_t rows;
	uint8_t currentX;
	uint8_t currentY;

public:
	HD44780(uint8_t cols, uint8_t rows);
	virtual ~HD44780();

	void cmd(uint8_t cmd);
	void cmd4bit(uint8_t cmd);
	void data(uint8_t data);
	void displayOn();
	void displayOff();
	void cursorOn();
	void cursorOff();
	void blinkOn();
	void blinkOff();
	void scrollLeft();
	void scrollRight();

	void clear();
	void cursorSet(uint8_t col, uint8_t row);
	void puts(uint8_t x, uint8_t y, char *str);
	void createChar(uint8_t location, uint8_t *chardata);
	void putCustom(uint8_t x, uint8_t y, uint8_t location);
	void simpleEnter(const char *text, int limit); //C
	void enterLines(const char *text1, const char *text2); //C
};
