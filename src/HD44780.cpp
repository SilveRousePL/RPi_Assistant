//
// Created by darek on 18.02.2018.
//

#include "HD44780.hpp"

HD44780::HD44780(uint8_t cols, uint8_t rows) :
		cols(cols), rows(rows), displayControl(HD44780_DISPLAYON),
		displayFunction(HD44780_4BITMODE | HD44780_5x8DOTS | HD44780_1LINE),
		displayMode(HD44780_ENTRYLEFT | HD44780_ENTRYSHIFTDECREMENT),
		currentX(0), currentY(0) {

	pinMode(HD44780_RS_PIN, OUTPUT);
	pinMode(HD44780_E_PIN, OUTPUT);
	pinMode(HD44780_D4_PIN, OUTPUT);
	pinMode(HD44780_D5_PIN, OUTPUT);
	pinMode(HD44780_D6_PIN, OUTPUT);
	pinMode(HD44780_D7_PIN, OUTPUT);
	digitalWrite(HD44780_RS_PIN, 0);
	digitalWrite(HD44780_E_PIN, 0);
	digitalWrite(HD44780_D4_PIN, 0);
	digitalWrite(HD44780_D5_PIN, 0);
	digitalWrite(HD44780_D6_PIN, 0);
	digitalWrite(HD44780_D7_PIN, 0);
	HD44780_Delay(4500);

	if (rows > 1) this->displayFunction |= HD44780_2LINE;

	cmd4bit(0x03);
	HD44780_Delay(4500);
	cmd4bit(0x03);
	HD44780_Delay(4500);
	cmd4bit(0x03);
	HD44780_Delay(4500);
	cmd4bit(0x02);
	HD44780_Delay(100);

	cmd(HD44780_FUNCTIONSET | this->displayFunction);
	displayOn();
	clear();

	cmd(HD44780_ENTRYMODESET | this->displayMode);

	HD44780_Delay(4500);
}

HD44780::~HD44780() {
}

void HD44780::cmd(uint8_t cmd) {
	HD44780_RS_LOW;

	cmd4bit(cmd >> 4);
	cmd4bit(cmd & 0x0F);
}

void HD44780::cmd4bit(uint8_t cmd) {
	digitalWrite(HD44780_D7_PIN, (cmd & 0x08));
	digitalWrite(HD44780_D6_PIN, (cmd & 0x04));
	digitalWrite(HD44780_D5_PIN, (cmd & 0x02));
	digitalWrite(HD44780_D4_PIN, (cmd & 0x01));
	HD44780_E_BLINK;
}

void HD44780::data(uint8_t data) {
	HD44780_RS_HIGH;

	cmd4bit(data >> 4);
	cmd4bit(data & 0x0F);
}

void HD44780::displayOn(void) {
	this->displayControl |= HD44780_DISPLAYON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::displayOff(void) {
	this->displayControl &= ~HD44780_DISPLAYON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::cursorOn(void) {
	this->displayControl |= HD44780_CURSORON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::cursorOff(void) {
	this->displayControl &= ~HD44780_CURSORON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::blinkOn(void) {
	this->displayControl |= HD44780_BLINKON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::blinkOff(void) {
	this->displayControl &= ~HD44780_BLINKON;
	cmd(HD44780_DISPLAYCONTROL | this->displayControl);
}

void HD44780::scrollLeft(void) {
	cmd(HD44780_CURSORSHIFT | HD44780_DISPLAYMOVE | HD44780_MOVELEFT);
}

void HD44780::scrollRight(void) {
	cmd(HD44780_CURSORSHIFT | HD44780_DISPLAYMOVE | HD44780_MOVERIGHT);
}

void HD44780::clear(void) {
	cmd(HD44780_CLEARDISPLAY);
	HD44780_Delay(3000);
}

void HD44780::cursorSet(uint8_t col, uint8_t row) {
	uint8_t row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row >= this->rows) {
		row = 0;
	}
	this->currentX = col;
	this->currentY = row;
	cmd(HD44780_SETDDRAMADDR | (col + row_offsets[row]));
}

void HD44780::puts(uint8_t x, uint8_t y, char *str) {
	cursorSet(x, y);
	while (*str) {
		if (this->currentX >= this->cols) {
			this->currentX = 0;
			this->currentY++;
			cursorSet(this->currentX, this->currentY);
		}
		if (*str == '\n') {
			this->currentY++;
			cursorSet(this->currentX, this->currentY);
		} else if (*str == '\r') {
			cursorSet(0, this->currentY);
		} else {
			data(*str);
			this->currentX++;
		}
		str++;
	}
}

void HD44780::createChar(uint8_t location, uint8_t *chardata) {
	uint8_t i;
	location &= 0x07;
	cmd(HD44780_SETCGRAMADDR | (location << 3));

	for (i = 0; i < 8; i++) {
		data(chardata[i]);
	}
}

void HD44780::putCustom(uint8_t x, uint8_t y, uint8_t location) {
	cursorSet(x, y);
	data(location);
}

void HD44780::simpleEnter(const char *text, int limit) {
	for (int i = 0; i < limit; i++) {
		if (text[i] == 0)
			break;
		data(text[i]);
	}
}

void HD44780::enterLines(const char *text1, const char *text2) {
	clear();
	for (int i = 0; i < 16; i++) {
		if (text1[i] == 0)
			break;
		data(text1[i]);
	}
	cmd(0xC0);
	for (int i = 0; i < 16; i++) {
		if (text2[i] == 0)
			break;
		data(text2[i]);
	}
}
