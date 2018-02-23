#include <vector>
#include <iostream>
#include "Relay.h"

extern "C" {
	#include "wiringPi.h"
}

const int RELAY_SIZE = 4;
const int RELAYS[] = { 1, 3, 2, 0 };

using namespace std;

void setup() {
	wiringPiSetup();
	for(int i = 0; i < RELAY_SIZE; i++)
		pinMode(RELAYS[i], OUTPUT);
}

vector<int> timeUntil(vector<int> source, vector<int> target) {
        int hours = target[0] - source[0];
        int minutes = target[1] - source[1];
        if (hours < 0)
                hours += 24;
        if (minutes < 0) {
                hours--;
                minutes+= 60;
        }
        vector<int> result;
        result.push_back(hours);
        result.push_back(minutes);
        return result;
}

int main(int argc, char * argv[]) {

	cout 	<< "  _________              __            _________                       \n"
		<< " /   _____/ ____ _____  |  | __ ____   \\_   ___ \\_____     ____   ____  \n"
		<< " \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /    \\  \\/\\__  \\   / ___\\_/ __ \\ \n"
		<< " /        \\   |  \\/ __ \\|    <\\  ___/  \\     \\____/ __ \\_/ /_/  >  ___/ \n"
		<< "/_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /\\___  / \\___  >\n"
		<< "        \\/     \\/     \\/     \\/    \\/          \\/     \\//_____/      \\/ \n"
		<< "   _____          __                         __  .__                    \n"
		<< "  /  _  \\  __ ___/  |_  ____   _____ _____ _/  |_|__| ____   ____       \n"
		<< " /  /_\\  \\|  |  \\   __\\/  _ \\ /     \\\\__  \\\\   __\\  |/  _ \\ /    \\      \n"
		<< "/    |    \\  |  /|  | (  <_> )  Y Y  \\/ __ \\|  | |  (  <_> )   |  \\     \n"
		<< "\\____|__  /____/ |__|  \\____/|__|_|  (____  /__| |__|\\____/|___|  /     \n"
		<< "        \\/                         \\/     \\/                    \\/      \n";
	setup();

	vector<Relay> relays;

	RelayTime t1;
	t1.setHour(16);
	t1.setMinute(15);

	RelayTime t2;
	t2.setHour(16);
	t2.setMinute(12);

	RelayTime t3 = t2 - t1;

	cout << "t3 to string: " << t3.toString() << "\n";

	for(int i = 0; i < RELAY_SIZE; i++) {
		cout << "Creating Relay " << i << "...\n";
		Relay r;
		r.setPinNumber(RELAYS[i]);
		r.setType(ARDUINO);
		relays.push_back(r);
	}

	for(int i = 0; i < RELAY_SIZE; i++) {
		relays[i].turnOn();
		delay(1000);
		relays[i].turnOff();
	}
	cout << "Done!\n";
}


