 # include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

#define PIN9             9

#define PIN10            10
#define PIN11            11

#define NUMPIXELS        20



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN11, NEO_GRB + NEO_KHZ800);

int pushButton = 2;
int delayval = 5; 

void setup() {
pixels.begin();
pixels2.begin();
pixels3.begin();
pinMode(pushButton, INPUT);
}

void loop() {

  if (digitalRead(pushButton) == LOW){
  for(int i=0;i<NUMPIXELS;i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 250,250,250 (WHITE)
      pixels.setPixelColor(i, pixels.Color(250,000,000)); 
      pixels.show();
      pixels2.setPixelColor(i, pixels2.Color(0,0,250)); 
      pixels2.show();
      pixels3.setPixelColor(i, pixels3.Color(0,0,250)); 
      pixels3.show();
      delay(delayval);  
    }
  }
    delay(500);
   if ((digitalRead(pushButton) == HIGH)){ 
  for(int i=0;i<NUMPIXELS;i++){
      pixels.setPixelColor(i, pixels.Color(250,0,0)); 
      pixels.show();
      pixels2.setPixelColor(i, pixels2.Color(0,0,0)); 
      pixels2.show();
      pixels3.setPixelColor(i, pixels3.Color(0,0,0)); 
      pixels3.show();

   }
   }
   delay(5);
}

