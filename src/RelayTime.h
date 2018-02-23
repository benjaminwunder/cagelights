#ifndef RELAYTIME_H
#define RELAY_H

#include <vector>
#include <string>

using namespace std;

class RelayTime
{
        public:
                RelayTime() : hour(0), minute(0) {}
		RelayTime(string time);

                void setTime(vector<int> time);               	//set the time as a vector
                void setTime(int hour, int minute);	     	//set the time with hours and minutes

		int getHour() const;
		int getMinute() const;

		void setHour(int hour);
		void setMinute(int minute);

                vector<int> getTime() const;
		string toString() const;

		bool operator==(const RelayTime& other);
                bool operator!=(const RelayTime& other);
		RelayTime operator-(const RelayTime& other);
        private:
		int hour;
		int minute;
};
#endif
