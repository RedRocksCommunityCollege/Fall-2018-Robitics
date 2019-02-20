/*
NATHANIEL'S SERVO CODE
*/



#include <Servo.h>
const int servoPin = 8;
const int buttonPin = 9;
int buttonState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(8);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (directionState == 0);{
    if (buttonState == HIGH){
      directionState = 1;
      for (pos = 0; pos <= 80; pos += 1){
        myservo.write(pos);
        delay(15);
        }
      }
    
  else if (directionState == 1){
    if (buttonState == HIGH){
      directionState = 0;
      for (pos = 80; pos >= 0; pos -= 1){
        myservo.write(pos);
        delay(15);
        }
      }
    }
  }
}
