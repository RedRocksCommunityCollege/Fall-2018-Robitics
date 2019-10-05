#include "Servos4Tiamat.h"

Dragon white("White", 13, 10, 40, 40);
Dragon black("Black", 12, 155, 60, 180);
Dragon green("Green", 9, 60, 30, 95);
Dragon blue("Blue", 10, 115, 30, 150);
Dragon red("Red", 11, 130, 40, 170);

void setup() {
	Serial.begin(9600);
	while(! Serial); // Wait until Serial is ready - Leonardo
	Serial.println("Starting\n");
}

void loop() {

	white.openCloseMouth();
	black.openCloseMouth();
  green.openCloseMouth();
  blue.openCloseMouth();
  red.openCloseMouth();

}
