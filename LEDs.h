#ifndef LEDS_H_
#define LEDS_H_
#include "Adafruit_NeoPixel.h"

class Dragon : Adafruit_NeoPixel{
private:
	String color;
	int pinNumHead;
	int pinNumNeck;
	int numberLEDsHead;
	int numberLEDsNeck;
	uint8_t red;
	uint8_t green;
	uint8_t blue;

public:
	Dragon ();
	Dragon (String c);
	Dragon (String c, int ph, int pn, int lh, int ln);
	Dragon (String c, int ph, int pn, int lh, int ln, uint8_t r, uint8_t g, uint8_t b);
	int getPinNumHead();
	void setPinNumHead(int ph);
	int getPinNumNeck();
	void setPinNumNeck(int pn);
	int getNumberLEDsHead();
	void setNumberLEDsHead(int lh);
	int getNumberLEDsNeck();
	void setNumberLEDsNeck(int ln);
	String getColor();
	void setColor(String c);
	uint8_t getRed();
	void setRed(uint8_t r);
	uint8_t getGreen();
	void setGreen(uint8_t g);
	uint8_t getBlue();
	void setBlue(uint8_t b);
	void printValues();
	void chaseNeck();
	void lightHead();
	void start();
	~Dragon ();
};

#endif /* CAR_H_ */
