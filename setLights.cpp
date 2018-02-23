#include <vector>
#include <iostream>
#include "Relay.h"
extern "C" {
	#include "wiringPi.h"
}

const int RELAY_SIZE = 4;
const int RELAYS[] = { 1, 3, 2, 0 };


void setup() {
	wiringPiSetup();
	for(int i = 0; i < RELAY_SIZE; i++)
		pinMode(RELAYS[i], OUTPUT);
}

int main() {

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
	for(int i = 0; i < RELAY_SIZE; i++) {
		cout << "Creating Relays!\n";
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


