#include <vector>
#include <iostream>
#include "Relay.h"
 
extern "C" {
	#include "wiringPi.h"
}

//state get/set
int Relay::getState() const {
	return this->state;
}
void Relay::setState(int state) {
	this->state = state;
}

//relayType get/set
int Relay::getType() const {
	return this->relayType;
}
void Relay::setType(int type) {
	this->relayType = type;
}

//turn on/off
void Relay::turnOn() {
	if (this->relayType == ARDUINO)
		this->setState(low);
	else
		this->setState(high);

	this->writeState();
}
void Relay::turnOff() {
	if (this->relayType == ARDUINO)
		this->setState(high);
	else
		this->setState(low);

	this->writeState();
}

void Relay::writeState() {
	digitalWrite(this->pinNumber, this->state);
}

//pinNumber get/set
int Relay::getPinNumber() const {
	return this->pinNumber;
}
void Relay::setPinNumber(int pinNumber) {
	this->pinNumber = pinNumber;
}

//get On/Off time
RelayTime Relay::getTimeOn() const {
	return timeOn;
}
RelayTime Relay::getTimeOff() const {
	return timeOff;
}

void Relay::setTimeOn(RelayTime timeOn) {
	this->timeOn = timeOn;
}

void Relay::setTimeOff(RelayTime timeOff) {
	this->timeOff = timeOff;
}
