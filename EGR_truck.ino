#include "src/Gearbox.hpp"

Gearbox* gearbox = nullptr;

void setup() {
    gearbox = getGearbBox(false, false, 12, 13);
}

void loop() {
    forward(gearbox);
    delay(500);
    stop(gearbox);
    delay(500);
    reverse(gearbox);
    delay(500);
    stop(gearbox);
    delay(500);
}