// much of this was taken from the "100-line" FastLED demo reel code.
// the alternating red/green code is credited inline below.
// my additions are fireflies, frost.

#include <FastLED.h>
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 500 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB
#define BRIGHTNESS 65 //this keeps voltage low, could go up a bit and will test out brighter levels once power is properly addressed.
#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { juggle, stripes1, fireflies, solid, rainbow, rainbowWithGlitter, frost, sinelon };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0;                  // rotating "base color" used by many of the patterns


void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND);

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; }   // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 60 ) { nextPattern(); } // change patterns periodically

}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}


//color patterns start here

//source: https://github.com/Resseguie/FastLED-Patterns/blob/master/fastled-patterns.ino
void stripes1( int width){
  for(int i=0; i<NUM_LEDS; i++){
    if(i % (width * 2) < width){
      leds[i] = CRGB::Red;
    }
   else{
      leds[i] = CRGB::Green;
    }
 }
}

void fireflies(){
  // adapted from the 100-line demo reel code's "confetti" effect
  fadeToBlackBy ( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CRGB::Gold;
}

void frost(){
  // adapted from the 100-line demo reel code's "confetti" effect
  fadeToBlackBy ( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CRGB::Blue;
}


void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

void solid() {
for(int i = 0; i < NUM_LEDS; i++ ){
  leds[i] = CHSV(random8(),255,255);
  }
  delay(3000); // nice delay between color changes
}

void rainbow() {
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter() {
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void sinelon(){
  fadeToBlackBy ( leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
}


void addGlitter( fract8 chanceOfGlitter) {
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}
