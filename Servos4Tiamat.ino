/*
/ * LEDs.cpp
/ *
/ *  Created on: Sep 20, 2019
/ *      Author: tyler leclear
/ */

#include "Servos4Tiamat.h"

Dragon::Dragon() {
	color = "";
	pinNum = 0;
	openAngle = 0;
	chompSpeed = 0;
	closedAngle = 0;
}

Dragon::Dragon(String c) {
	color = c;
	pinNum = 0;
	openAngle = 0;
	chompSpeed = 0;
	closedAngle = 0;
}

Dragon::Dragon(String c, int p, int ca, int cs, int oa) {
	color = c;
	pinNum = p;
	openAngle = oa;
	chompSpeed = cs;
  closedAngle = ca;
}

int Dragon::getPinNum() {
	return pinNum;
}

void Dragon::setPinNum(int p) {
	this->pinNum = pinNum;
}

int Dragon::getOpenAngle() {
	return openAngle;
}

void Dragon::setOpenAngle(int oa) {
	this->openAngle = openAngle;
}

int Dragon::getClosedAngle() {
	return closedAngle;
}

void Dragon::setClosedAngle(int ca) {
	this->closedAngle = closedAngle;
}

int Dragon::getChompSpeed() {
	return chompSpeed;
}

void Dragon::setChompSpeed(int cs){
	this->chompSpeed = chompSpeed;
}

void Dragon::openCloseMouth() {
	int pos = 0;    // variable to store the servo position
	mouth.attach(getPinNum());  // attaches the servo on pin 9 to the servo object
	for (pos = getClosedAngle(); pos <= getOpenAngle(); pos += 1) { // goes from 0 degrees to 180 degrees
	    // in steps of 1 degree
	    mouth.write(pos);              // tell servo to go to position in variable 'pos'
	    delay(getChompSpeed());                       // waits ?ms for the servo to reach the position
	  }
	for (pos = getOpenAngle(); pos >= getClosedAngle(); pos -= 1) { // goes from 180 degrees to 0 degrees
		    mouth.write(pos);              // tell servo to go to position in variable 'pos'
		    delay(getChompSpeed());                       // waits ?ms for the servo to reach the position
		  }
}

Dragon::~Dragon() {
	// TODO Auto-generated destructor stub
}
