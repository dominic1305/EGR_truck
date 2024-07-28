# Components List

* 150186 dc motor (x1)
* XC4419 5V relay (x2)
* HC-SR04 (x1)
* Arduino UNO (x1)

# Wiring Table

| Idx | Wire | Origin | Destination |
| :-: | :-: | :-: | :-: |
| 0 | Motor PS1 | Arduino 3.5V | Relay1 NO socket |
| 1 | Motor PS2 | Arduino 3.5V | Relay2 NO socket |
| 2 | Motor GND1 | Relay1 NC socket | Arduino GND |
| 3 | Motor GND2 | Relay2 NC socket | Arduino GND |
| 4 | Relay1 PS | Arduino 5V | Relay1 V pin |
| 5 | Relay2 PS | Arduino 5V | Relay2 V pin |
| 6 | Relay1 GND | Relay1 G pin | Arduino GND |
| 7 | Relay2 GND | Relay2 G pin | Arduino GND |
| 8 | Relay1 signal | Arduino pin 13 | Relay1 S pin |
| 9 | Relay2 signal | Arduino pin 12 | Relay2 S pin |
| 10 | Ultrasonic PS | Arduino 5V | Ultrasonic VCC |
| 11 | Ultransoic GND | Ultrasonic GND | Arduino GND |
| 12 | Ultrasonic trig | Arduino pin 8 | Ultrasonic trig pin |
| 13 | Ultrasonic echo | Arduino pin 9 (PWM) | Ultransoic echo pin |