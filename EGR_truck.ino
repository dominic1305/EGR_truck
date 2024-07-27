#include "src/Gearbox.hpp"
#include "src/Eyes.hpp"

Gearbox* gearbox = nullptr;
Sensor* sensor = nullptr;
bool state = false;

void setup() {
	Serial.begin(9600);

	gearbox = getGearbox(false, false, 12, 13);
	sensor = getSensor(8, 9);
}

void loop() {
	if (state) return; //program is complete

	if (!withinThreshold(sensor, 30, true)) {
		auto time = millis() - 200;

		while (time * 2 > millis()) {//take the same amount of time backwards as forwards
			reverse(gearbox);
			delay(100);

			stop(gearbox);
			delay(100);
		}

		state = true;
		return;
	}

	forward(gearbox);
	delay(100);

	stop(gearbox);
	delay(100);
}