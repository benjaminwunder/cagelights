#include <vector>
#include <iostream>
#include "Relay.h"
#include <boost/program_options.hpp>
#include <string>
 
extern "C" {
	#include "wiringPi.h"
}

const int RELAY_SIZE = 4;
const int RELAYS[] = { 1, 3, 2, 0 };

using namespace std;
namespace po = boost::program_options;

void setup() {
	wiringPiSetup();
	for(int i = 0; i < RELAY_SIZE; i++)
		pinMode(RELAYS[i], OUTPUT);
}

int main(int argc, char * argv[]) {

	string onTime;
	string offTime;

	po::options_description desc{"Options"};
	desc.add_options()
	  ("help,h", "Help Screen")
	  ("ontime,o", po::value<string>(&onTime),"The time to activate all the relays")
	  ("offtime,f", po::value<string>(&offTime),"The time to de-activate all the relays");

	try {
		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
	}
	catch(const exception & e)
	{
		cerr << e.what() << endl << endl;
		cout << desc << endl;
	}
	RelayTime rOn(onTime);
	RelayTime rOff(offTime);
	cout << "On Time: " << rOn.toString() << " Off Time: " << rOff.toString() << endl;

	cout 	     << "  _________              __            _________"
		<< endl << " /   _____/ ____ _____  |  | __ ____   \\_   ___ \\_____     ____   ____"
		<< endl << " \\_____  \\ /    \\\\__  \\ |  |/ // __ \\  /    \\  \\/\\__  \\   / ___\\_/ __ \\"
		<< endl << " /        \\   |  \\/ __ \\|    <\\  ___/  \\     \\____/ __ \\_/ /_/  >  ___/"
		<< endl << "/_______  /___|  (____  /__|_ \\\\___  >  \\______  (____  /\\___  / \\___  >"
		<< endl << "        \\/     \\/     \\/     \\/    \\/          \\/     \\//_____/      \\/"
		<< endl << "   _____          __                         __  .__"
		<< endl << "  /  _  \\  __ ___/  |_  ____   _____ _____ _/  |_|__| ____   ____"
		<< endl << " /  /_\\  \\|  |  \\   __\\/  _ \\ /     \\\\__  \\\\   __\\  |/  _ \\ /    \\"
		<< endl << "/    |    \\  |  /|  | (  <_> )  Y Y  \\/ __ \\|  | |  (  <_> )   |  \\"
		<< endl << "\\____|__  /____/ |__|  \\____/|__|_|  (____  /__| |__|\\____/|___|  /"
		<< endl << "        \\/                         \\/     \\/                    \\/"
		<< endl;

	setup();

	vector<Relay> relays;

	RelayTime timeDiff = rOff - rOn;

	cout << "Relays will be active for : " << timeDiff.getHour() << " hours and " << timeDiff.getMinute() << " minutes." << endl;

	cout << "Creating Relays..." << endl;
	for(int i = 0; i < RELAY_SIZE; i++) {
		Relay r;
		r.setPinNumber(RELAYS[i]);
		r.setType(ARDUINO);
		r.setTimeOn(rOn);
		r.setTimeOff(rOff);
		relays.push_back(r);
	}

	cout << "Testing Relays.  Please verify the board is responding appropriately." << endl;
	for(int i = 0; i < RELAY_SIZE; i++) {
		cout << i << " " << flush;
		relays[i].turnOn();
		delay(2000);
		relays[i].turnOff();
	}
	cout << "Done!\n";
}


