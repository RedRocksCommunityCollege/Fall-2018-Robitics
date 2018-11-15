bool mouthClosed;


#include <Servo.h>
Servo myservo3;

//String input = "on";
int theSwitch = 4;
int switchVal;
int pos = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  myservo3.attach(6);
}


void loop() {
  // put your main code here, to run repeatedly:
 switchVal = digitalRead(theSwitch);
  if (switchVal == HIGH && mouthClosed == true)
  {
    
    
      for (int pos = 180; pos >= 130; pos -= 1)
      { // goes from 180 degrees to 0 degrees
        myservo3.write(pos);              // tell servo to go to position in variable 'pos'
       
      }
       mouthClosed = false;
    }
      if (switchVal == LOW && mouthClosed == false)
      {
        
          for (int pos = 130; pos <= 180; pos += 1)
          { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            myservo3.write(pos);              // tell servo to go to position in variable 'pos'
           
          }
           mouthClosed = true;
        }
      
    }
