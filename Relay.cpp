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
vector<int> Relay::getOnTime() const {
	vector<int> result;
	result.push_back(this->onHour);
	result.push_back(this->offMinute);
	return result;
}
vector<int> Relay::getOffTime() const {
	vector<int> result;
	result.push_back(this->offHour);
	result.push_back(this->offMinute);
	return result;
}

//set Time
void Relay::setTime(vector<int> onTime, vector<int> offTime) {
	bool failCheck = false;
	string failReason = "";
	if (0 > onTime[0] || onTime[0] > 12) {
		failReason += "On Time Hour is out of bounds. ";
		failCheck = true;
	}

	if (0 > onTime[1] || onTime[1] > 59) {
		failReason += "On Timed Minute is out of bounds. ";
		failCheck = true;;
	}
	if (0 > offTime[0] || offTime[0] > 12) {
		failReason += "Off Time Hour is out of bounds";
		failCheck = true;
	}

	if (0 > offTime[1] || offTime[1] > 59) {
		failReason += "Off Timed Minute is out of bounds";
		failCheck = true;
	}

	if (failCheck) {
		cout << "Could Not Set Time.  Reasons: " << failReason << "\n";
		return;
	}

	this->onHour = onTime[0];
	this->offHour = offTime[0];

	this->onMinute = onTime[1];
	this->offMinute = offTime[1];
}

void Relay::setTime(int onHour, int onMinute, int offHour, int offMinute) {
	vector<int> onTime;
	vector<int> offTime;

	onTime.push_back(onHour);
	onTime.push_back(onMinute);

	offTime.push_back(offHour);
	offTime.push_back(offMinute);
}

bool Relay::operator==(const Relay& other) {
	if (this->onHour == other.getOnTime()[0] && this->onMinute == other.getOnTime()[1]
		&& this->offHour == other.getOffTime()[0] && this->offMinute == other.getOffTime()[1])
		return true;
	return false;
}
