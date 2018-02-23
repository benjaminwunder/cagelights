#include "RelayTime.h"
#include <vector>
#include <string>
#include <iostream>

void RelayTime::setTime(vector<int> time) {
	if (time.size() > 2) {
		cout << "Error in RelayTime.setTime(vector<int>): Time Vector must be in the form of [hour, minute]\n";
		return;	
	}
	setTime(time[0], time[1]);
}

void RelayTime::setTime(int hour, int minute) {

	bool passedCheck = true;
	if ( hour < 0 || 24 <= hour) {
		cout << "Error in RelayTime.setTime(int, int): Hour must be between 0 and 23 (inclusive)\n";
		passedCheck = false;
	}

	//set Minute
	if (minute < 0 || 60 <= minute) {
		cout << "Error in RelayTime.setTime(int, int): Minute must be between 0 and 59( inclusive)\n";
		passedCheck = false;
	}

	if (passedCheck) {
		this->hour = hour;
		this->minute = minute;
	}
}
vector<int> RelayTime::getTime() const {
	vector<int> result;
	result.push_back(this->hour);
	result.push_back(this->minute);
	return result;
}

string RelayTime::toString() const {
	string result = "";

	if (this->hour < 10)
		result += "0";

	result += to_string(this->hour) + ":";

	if (this->minute < 10)
		result += "0";

	result += to_string(this->minute);

	return result;
}

int RelayTime::getHour() const {
	return this->hour;
}

int RelayTime::getMinute() const {
	return this->minute;
}

void RelayTime::setHour(int hour) {
	if (hour < 0 || 24 <= hour)
		cout << "Error in RelayTime.setHour(): Hour must be between 0 and 23 (inclusive)\n";
	else
		this->hour = hour;
}

void RelayTime::setMinute(int minute) {
	if (minute < 0 || 60 <= minute)
		cout << "Error in RelayTime.setMinute(): Minute must be between 0 and 59 (inclusive)\n";
	else
		this->minute = minute;
}

bool RelayTime::operator== (const RelayTime& other) {
	if (this->hour == other.hour && this->minute == other.minute)
		return true;
	return false;
}

bool RelayTime::operator!= (const RelayTime& other) {
	return !(*this == other);
}
RelayTime RelayTime::operator- (const RelayTime& other) {
	int hr = this->hour;
	int min = this->minute;

	hr -= other.hour;
	min -= other.minute;

	if (min < 0) {
		min += 60;
		hr--;
	}
	if (hr < 0) {
		hr += 24;
	}
	RelayTime r;
	r.setHour(hr);
	r.setMinute(min);
	return r;
}

