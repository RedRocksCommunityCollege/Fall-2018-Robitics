#include <Arduino.h>
#include "LEDs.h"

Dragon white("White", 13, 12, 15, 48, 0, 0, 255); //Should just add another pinNum for the neck.
Dragon black("Black", 11, 10, 15, 48, 127, 0, 255);
Dragon green("Green", 5, 4, 15, 48, 0, 255, 0);
Dragon blue("Blue", 7, 6, 15, 48, 255, 255, 0);
Dragon red("Blue", 9, 8, 15, 48, 255, 0, 0);


void setup() {
	Serial.begin(9600);
	while(! Serial); // Wait until Serial is ready - Leonardo
	Serial.println("Starting\n");

}

void loop() {

	white.lightHead();
  black.lightHead();
  green.lightHead();
  blue.lightHead();
  red.lightHead();


	white.chaseNeck();
	black.chaseNeck();
  green.chaseNeck();
  blue.chaseNeck();
  red.chaseNeck();

}
