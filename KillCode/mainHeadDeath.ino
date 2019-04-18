#include <Servo.h> 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN10            10
#define NUMPIXELS        50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN10, NEO_GRB + NEO_KHZ800);

int on = 7;
int relayOne = 12;  
int relayTwo = 11;  
const int on_if = 0;
int delayval = 50; 
int killPin = 13;

const int servoPin = 8;  // Servo pin
const int buttonPin = 9;  // Pushbutton pin
int buttonState = 0; 
int directionState = 0; 
Servo myservo; 
int pos = 50;



void setup() {
  myservo.attach(8);
  pixels.begin();
  
  pinMode(on, OUTPUT);
  pinMode(relayOne, OUTPUT);
  pinMode(relayTwo, OUTPUT);
}

 void loop(){
  
  
  for(int i=0;i<NUMPIXELS;i++){
  
  pixels.setPixelColor(i, pixels.Color(250,0,0));
  pixels.show();
  }
  digitalWrite(on, LOW); 
  
  //CHANGE THIS NUMBER TO CHANGE THE TIME DELAY BETWEEN ACTIONS
  delay(10000);
  digitalWrite(relayOne, HIGH);
  digitalWrite(relayTwo, HIGH);
  delay(1000);
  digitalWrite(on, HIGH);
       for(pos = 50; pos <= 90; pos += 1)
       {
         myservo.write(pos);
         delay(15);
       }
       
  delay(2000); // CHANGE THIS NUMBER TO CHANGE HOW LONG THE MOTOR IS ACTIVE
  digitalWrite(on, LOW);
  delay(1000); //CHANGE THIS NUMBER TO CHANGE THE TIME DELAY BETWEEN ACTIONS
  digitalWrite(relayOne, LOW);
  digitalWrite(relayTwo, LOW);
  delay(10000);
  digitalWrite(on, HIGH);
 
       for (pos = 90; pos >= 50; pos -=1){
         myservo.write(pos);
         delay(15);  // waits 15ms to reach the position.
       }
  delay(2000); // CHANGE THIS NUMBER TO CHANGE HOW LONG THE MOTOR IS ACTIVE

  if (digitalRead(killPin) == HIGH){
      for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
        pixels.show();
        delay(100);
      }
      if (pos != 90){
        myservo.write(90);       
       }
      digitalWrite(relayOne, HIGH);
      digitalWrite(relayTwo, HIGH);
      delay(250);
      digitalWrite(on, LOW);
      
      //write neck fall here
      digitalWrite(on, HIGH);
        for(pos = 50; pos <= 90; pos += 1){
         myservo.write(pos);
         delay(15);
       }
       }
}
