bool mouthClosed;


#include <Servo.h>
Servo myservo3;

//String input = "";//
int theSwitch = 4;
int switchVal;
int pos = 180;
int theSwitch2 = 2;
int switchVal2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo3.attach(6);
  pinMode(theSwitch, INPUT);
  pinMode(theSwitch, INPUT);
  myservo3.write(180);
}


void loop() {
  // put your main code here, to run repeatedly:
  switchVal = digitalRead(theSwitch);
  switchVal2 = digitalRead(theSwitch2);
  myservo3 = digitalRead(servo);
// input = Serial.readString();
  Serial.println(switchVal);
    Serial.println(switchVal2);
  Serial.println(servo);
  if (switchVal == HIGH && mouthClosed == true && switchVal2 == LOW)
  {


    for (int pos = 180; pos >= 130; pos -= 1)
    { // goes from 180 degrees to 0 degrees
      myservo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);
    }
    mouthClosed = false;
 
  }
 else if (switchVal == LOW && mouthClosed == false && switchVal2 ==LOW)
  {

    for (int pos; pos <= 180; pos += 1)
    { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);

    }
    mouthClosed = true;
  }

  else if (switchVal2 == HIGH && mouthClosed == true && switchVal == LOW)
  {


    for (int pos = 180; pos >= 170; pos -= 1)
    { // goes from 180 degrees to 90 degrees
      myservo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(50);
    }
    mouthClosed = false;
  }

}
