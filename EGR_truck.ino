#include "src/Gearbox.hpp"
#include "src/Eyes.hpp"

Gearbox* gearbox = nullptr;
Sensor* sensor = nullptr;

void setup() {
	Serial.begin(9600);

	gearbox = getGearbox(false, false, 12, 13);
	sensor = getSensor(8, 9);
}

void loop() {
	Serial.println(getDistance(sensor, 30) ? "under" : "over");
}