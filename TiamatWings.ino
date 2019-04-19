int x;
const int buttonPin = 9;
const int stepPin = 6;
const int dirPin = 4;
//int buttonState = 0;
//int directionState = 0;
const int onOffRelay = 7;
const int dir1Relay = 11;
const int dir2Relay = 12;
const int killPin = 2;

void setup() {
  // put your setup code here, to run once:
    //Stepper Motor 
      pinMode(buttonPin,INPUT);
      pinMode(stepPin, OUTPUT);
      pinMode(dirPin, OUTPUT);
    //Torque Motor
      pinMode(onOffRelay, OUTPUT);
      pinMode(dirCW1Relay, OUTPUT);
      pinMode(dirCW2Relay, OUTPUT);  
    //Kill Pin
      pinMode(killPin, INPUT); 
}

void loop() {
  //Tiamat Enters. Open and extends wings.
    //Extending wing
      digitalWrite(dirPin, LOW);
      for(x = 0; x < 4000; x++) //Iterations may need adjustment
      {
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      }
    
    //Opening wing.
      digitalWrite(onOffRelay, HIGH);
      delay(1000); //May need adjustment
      digitalWrite(onOffRelay, LOW);

  //Tiamat default. Extended and flapping.
    //Flapping wing.
    while(!digitalRead(killPin))
    {
      digitalWrite(onOffRelay, HIGH);
      digitalWrite(dirCW1Relay, HIGH);
      digitalWrite(dirCW2Relay, HIGH);
      delay(1000); //May need adjustment
      digitalWrite(onOffRelay, HIGH);
      digitalWrite(dirCW1Relay, LOW);
      digitalWrite(dirCW2Relay, LOW);
      delay(1000); //May need adjustment
    }
    digitalWrite(onOffRelay, LOW); //Turns off Torque Motor

  //Tiamat Dies. 
     //Wing contracts.
       digitalWrite(dirPin, HIGH);
       for(x = 0; x < 4000; x++)//Iterations may need adjustment
       {
         digitalWrite(stepPin, LOW);
         delayMicroseconds(500);
         digitalWrite(stepPin, HIGH);
         delayMicroseconds(500);
       }
     //Wing closes forward.
      digitalWrite(onOffRelay, HIGH);
      digitalWrite(dirCW1Relay, HIGH);
      digitalWrite(dirCW2Relay, HIGH);
      delay(1000); //May need adjustment
      digitalWrite(onOffRelay, LOW);
      digitalWrite(dirCW1Relay, LOW);
      digitalWrite(dirCW2Relay, LOW);
}
