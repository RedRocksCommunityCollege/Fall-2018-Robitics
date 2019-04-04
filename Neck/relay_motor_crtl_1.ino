int on = 7;
int relayOne = 12;
int relayTwo = 11;
const int on_if = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(on, OUTPUT);
  pinMode(relayOne, OUTPUT);
  pinMode(relayTwo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(on, LOW); //CHANGE THIS NUMBER TO CHANGE THE TIME DELAY BETWEEN ACTIONS
  delay(2000);
 // digitalWrite(relayOne, HIGH);
 // digitalWrite(relayTwo, HIGH);
 // delay(2000);
  digitalWrite(on, HIGH);
  delay(3000); // CHANGE THIS NUMBER TO CHANGE HOW LONG THE MOTOR IS ACTIVE
  digitalWrite(on, LOW);
  delay(2000); //CHANGE THIS NUMBER TO CHANGE THE TIME DELAY BETWEEN ACTIONS
//  digitalWrite(relayOne, LOW);
//  digitalWrite(relayTwo, LOW);
//  delay(2000);
  digitalWrite(on, HIGH);
  delay(3000); // CHANGE THIS NUMBER TO CHANGE HOW LONG THE MOTOR IS ACTIVE
}
