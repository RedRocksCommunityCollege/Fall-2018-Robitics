/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */

#include <Servo.h> // servo library
Servo myservo; //declare servo
 
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo

const int ledSysPin = 8;    //send HIGH signal here to initiate kill command at other arduinos.
const int jawSysPin = 7;
const int eyeSysPin = 6;
const int primaryTwoHeadsSysPin = 5;

long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  delay(3000);
  myservo.attach(2); // control servo at digital pin 2

  
  
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  if(inches <= 2){
    digitalWrite(ledSysPin, HIGH);
    digitalWrite(jawSysPin, HIGH);
    digitalWrite(eyeSysPin, HIGH);
    digitalWrite(primaryTwoHeadsSysPin, HIGH);
    
    Serial.println("I'm B A T H A N.");
    
    }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
