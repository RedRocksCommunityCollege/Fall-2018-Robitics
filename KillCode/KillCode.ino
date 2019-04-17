
#include <Servo.h> 
Servo myservo; //declare servo
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN9             9 //eye pin

#define PIN10            10 //neck pin
#define NUMPIXELS        47
#define NUMeyePIXELS     20

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN10, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMeyePIXELS, PIN9, NEO_GRB + NEO_KHZ800);

int jawVal = 0; //jaw system - make sure the signal pin is grounded
const int jawSysPin = 7;

//Ultrasonic sensor stuff
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo

/*
const int ledSysPin = 8;
const int jawSysPin = 7;
const int eyeSysPin = 6;
const int primaryTwoHeadsSysPin = 5;
*/

long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(jawSysPin, INPUT);
  
  delay(3000);
  myservo.attach(8); // control servo at digital pin 8
  pixels.begin();
  pixels2.begin();
  
  
}
 
void loop() {
  jawVal = LOW;
  jawVal = digitalRead(jawSysPin);
  
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

  //Important note: The kill command will run only once if the sword is extracted BEFORE the death sequence ends.
  //To Do: Implement neck drops from their intersections w/the body.
  //       See what angle would allow the jaws to hang open; currently set to 90 deg as a placeholder.
  if(inches <= 2){
    /*
    digitalWrite(ledSysPin, HIGH);
    digitalWrite(jawSysPin, HIGH);
    digitalWrite(eyeSysPin, HIGH);
    digitalWrite(primaryTwoHeadsSysPin, HIGH);
    */
    
    //Make the eyes and neck lights turn red for the specified delay value at the end of the loop
        for (int j=0; j <= 1;j++){
    pixels.fill(pixels.Color(250,0,0), 0, 47); 
    pixels.show();
    pixels2.fill(pixels.Color(250,0,0), 0, 20); 
    pixels2.show();
    /*
    pixels.fill(pixels2.Color(250,0,0), 0, 50); 
    pixels.show();
    pixels.fill(pixels3.Color(250,0,0), 0, 50); 
    pixels.show();
    */
    delay(5000);
    }
    //make the eye and neck LEDs fade to black along their respective strips
    for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 250,250,250 (WHITE)
      //A delay val inserted here will adjust the time interval between when one and the next pixels push a value.
      //"pixels" var turns on via a signal sent to D9.
      delay(161.7);
      pixels.setPixelColor(i, pixels.Color(0,0,0)); //slowly deactivate the neck lights
      pixels.show();

      pixels2.setPixelColor(i, pixels.Color(0,0,0)); //slowly deactivate the eye lights
      pixels2.show();
      
      /*
      pixels2.setPixelColor(i, pixels2.Color(0,0,0)); 
      pixels2.show();
      pixels3.setPixelColor(i, pixels3.Color(0,0,0)); 
      pixels3.show();  
      */
    }
    //sets the jaw servos to an angle val
    Serial.print(jawVal);
    myservo.write(90);
    
    Serial.println("I'm N A T H A N.");
    }
  //Miscellaneous data for meansuring distance via serial monitor for the ultrasonic sensor
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
