
//Ghost code based on the following
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// Also based on my original mrs pan man lantern ghosts.

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// We have the notion on if this is for the bottom (fade red and orange) or the top (white flashing).
#define ISBOTTTOM  1

// Which pin on the Arduino is connected to the Neostrip?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many Neostrip are attached to the Arduino?
#define NUMPIXELS      7

// When we setup the NeoPixel library, we tell it how many strip, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//Colors
uint32_t red = strip.Color(255, 0, 0);
uint32_t orange = strip.Color(255, 102, 0);
uint32_t cyan = strip.Color(0, 255, 255);
uint32_t pink = strip.Color(255, 182, 193);

uint32_t blue = strip.Color(0, 0, 255);
uint32_t black = strip.Color(0, 0, 0);

//Demo - Fandomize Ghost Color
uint32_t colorArr[4] = {red, orange, cyan, pink};
int numColors = 4;  //figure out how to get length of array ^^ says 14 so 4bytes?


int delayval = 1500; // delay for second
int delayBetweenHunt = 15000;

void setup() {
  Serial.begin(9600);
  Serial.println(sizeof(colorArr));
  strip.begin(); // This initializes the NeoPixel library.
  strip.show(); // Initialize all strip to 'off'
}

void loop() {
  strip.setBrightness(200);
  hunting(cyan, 100);
  delay(delayBetweenHunt);
  beingHunted(blue, delayval);
}

// When hunting stay on normal color
void hunting(uint32_t c, uint8_t wait) {
    for (int i=0; i < strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, c); 
    }
    strip.show();
    delay(wait);
}


//When Being Hunted
void beingHunted(uint32_t c, uint8_t wait) {
  for (int j=0; j<15; j++) {  //do 10 cycles of blinking
    for (int i=0; i < strip.numPixels(); i=i+1) {
      strip.setPixelColor(i, c);    //turn every pixel on
    }
    strip.show();
   
    delay(wait);
    strip.setBrightness(5);
    strip.show();
    delay(wait);
    strip.setBrightness(250);
    strip.show();
  }
}

//void pick random color
uint32_t pickAColor() {
  // Would be cooler with something like:
  //Serial.println(random(0, colorArr[(sizeof(colorArr) - 1)]));
  switch (random(0, (numColors-1))) {
  case 0:
    Serial.print('red');
    return red;
    break;
  case 1:
    Serial.print('orange');
    return orange;
    break;
  case 2:
    Serial.print('cyan');
    return cyan;
    break;
  case 3:
    Serial.print('pink');
    return pink;
    break;
  }
}
