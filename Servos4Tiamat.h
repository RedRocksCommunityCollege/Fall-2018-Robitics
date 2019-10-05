#ifndef SERVOS4TIAMAT_H_
#define SERVOS4TIAMAT_H_
#include "Servo.h"

class Dragon : Servo {
private:
	String color;
	int pinNum;
	int closedAngle;
	int chompSpeed;
	int openAngle;

public:
	Servo mouth;
	Dragon();
	Dragon(String c);
	Dragon(String c, int p, int ca, int cs, int oa);
	int getPinNum();
	void setPinNum(int p);
	int getOpenAngle();
	void setOpenAngle(int oa);
	int getClosedAngle();
	void setClosedAngle(int ca);
	int getChompSpeed();
	void setChompSpeed(int cs);
	void openCloseMouth();
	~Dragon();
};

#endif /* CAR_H_ */
