#ifndef RELAY_H
#define RELAY_H

#include <vector>
#include <string>

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

		vector<int> getOnTime() const;						//get the time in a vector
		vector<int> getOffTime() const;						//get the time in a vector
		void setTime(vector<int> onTime, vector<int> offTime);			//set the time as a vector
		void setTime(int onHour, int onMinute, int offHour, int offMinute);	//set the time with hours and minutes
		bool operator==(const Relay& other);
		bool operator!=(const Relay& other);
	private:
		int state;								//the state (on or off)
		int relayType;
		int pinNumber;								//the pin for this relay
		int onHour;
		int onMinute;
		int offHour;
		int offMinute;
};
#endif
