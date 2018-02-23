#ifndef RELAY_H
#define RELAY_H

#include <vector>
#include <string>
#include "RelayTime.h"

using namespace std;

enum stateValues { low, high };
enum relayType { ARDUINO, PI };

class Relay
{
	public:
		Relay() : state(low), pinNumber(-1) {}
		int getState() const;							//get the private state
     		void setState(int state);						//set the private state

		int getType() const;
		void setType(int setType);

		void turnOn();
		void turnOff();

		void writeState();

		int getPinNumber() const;						//return pin number
		void setPinNumber(int pinNumber);					//set the pin number

		RelayTime getTimeOn() const;						//get the time to turn on
		RelayTime getTimeOff() const;						//get the time to turn off

		void setTimeOn(RelayTime timeOn);					//set the time to turn on
		void setTimeOff(RelayTime timeOff);					//set the time to turn off

	private:
		int state;								//the state (low or high)
		int relayType;
		int pinNumber;								//the pin for this relay
		RelayTime timeOn;
		RelayTime timeOff;
};
#endif
