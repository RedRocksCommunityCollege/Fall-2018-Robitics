/*
 * LEDs.cpp
 *
 *  Created on: Sep 20, 2019
 *      Author: tyler leclear
 */

#include "LEDs.h"

Dragon::Dragon() {
	color = "";
	pinNumHead = 0;
	pinNumNeck = 0;
	numberLEDsHead = 0;
	numberLEDsNeck = 0;
	red = 0;
	green = 0;
	blue = 0;
}

Dragon::Dragon(String c) {
	color = c;
	pinNumHead = 0;
	pinNumNeck = 0;
	numberLEDsHead = 0;
	numberLEDsNeck = 0;
	red = 0;
	green = 0;
	blue = 0;
}

Dragon::Dragon(String c, int ph, int pn, int lh, int ln) {
	color = c;
	pinNumHead = ph;
	pinNumNeck = pn;
	numberLEDsHead = lh;
	numberLEDsNeck = ln;
	red = 0;
	green = 0;
	blue = 0;
}

Dragon::Dragon(String c, int ph, int pn, int lh, int ln, uint8_t r, uint8_t g, uint8_t b) {
	color = c;
	pinNumHead = ph;
	pinNumNeck = pn;
	numberLEDsHead = lh;
	numberLEDsNeck = ln;
	red = r;
	green = g;
	blue = b;
}

int Dragon::getPinNumHead() {
	return pinNumHead;
}

void Dragon::setPinNumHead(int ph) {
	this->pinNumHead = pinNumHead;
}

int Dragon::getPinNumNeck(){
	return pinNumNeck;
}

void Dragon::setPinNumNeck(int pn){
	this->pinNumNeck = pinNumNeck;
}

int Dragon::getNumberLEDsHead() {
	return numberLEDsHead;
}

void Dragon::setNumberLEDsHead(int lh) {
	this->numberLEDsHead = numberLEDsHead;
}

int Dragon::getNumberLEDsNeck() {
	return numberLEDsNeck;
}

String Dragon::getColor() {
	return color;
}

void Dragon::setColor(String c) {
	this->color = color;
}
uint8_t Dragon::getRed(){
	return red;
}
void Dragon::setRed(uint8_t r){
	this->red = red;
}
uint8_t Dragon::getGreen(){
	return green;
}
void Dragon::setGreen(uint8_t g){
	this->green = green;
}
uint8_t Dragon::getBlue(){
	return blue;
}
void Dragon::setBlue(uint8_t b){
	this->blue = blue;
}

void Dragon::printValues() {

	//Format output.
//	cout.setf(ios::fixed);
//	cout.setf(ios::showpoint);
//	cout.precision(2);
//
//	cout << "The make is: " << getManufactory() << endl;
//	cout << "The model is: " << getType() << endl;
//	cout << "The gas mileage is: " << getGasMileage() << "mpg" << endl;
//	cout << "The cost of the vehicle is: $" << getCost() << endl;
}

void Dragon::start() {
	Adafruit_NeoPixel dragon = Adafruit_NeoPixel(getNumberLEDsHead(), getPinNumHead(), NEO_GRB + NEO_KHZ800);
	dragon.begin();
	Serial.println("Starting: ");
	Serial.println(color);
	Serial.println("\n");
	delay(1000);
}

void Dragon::chaseNeck(){
	Adafruit_NeoPixel neck = Adafruit_NeoPixel(getNumberLEDsNeck(), getPinNumNeck(), NEO_GRB + NEO_KHZ800);
	neck.begin();
	for(uint16_t i=0; i<(getNumberLEDsNeck()+4); i++) {
		  neck.setPixelColor( i, getRed(), getGreen(), getBlue()); // Draw new pixel
		  neck.setPixelColor(i-4, 0); // Erase pixel a few steps back
		  neck.show();
	      delay(100);
	  }
	Serial.println("Strip chased: ");
	Serial.println(color);
	Serial.println("\n");
	delay(1000);
}

void Dragon::lightHead(){
	Adafruit_NeoPixel head = Adafruit_NeoPixel(getNumberLEDsHead(), getPinNumHead(), NEO_GRB + NEO_KHZ800);
	head.begin();
	head.fill(head.Color( getRed(), getGreen(), getBlue()));
	head.show();
	Serial.println("Strip filled: ");
	Serial.println(color);
	Serial.println("\n");
	delay(1000);
}

Dragon::~Dragon() {
	// TODO Auto-generated destructor stub
}
