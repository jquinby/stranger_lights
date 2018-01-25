

#include <FastLED.h>
#define DATA_PIN 6  //this is the data pin connected to the LED strip.  If using WS2801 you also need a clock pin
#define NUM_LEDS 50 //change this for the number of LEDs in the strip
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS]; 

int brightness = 0; //used for fading routine...maybe
int fadeAmount = 5; //used for fading routine
int z = 0;

// Found the following index bit on reddit

uint8_t getIndex(char c) {
switch (toLowerCase(c)) {
    case 'a': return 29;
    case 'b': return 30;
    case 'c': return 32;
    case 'd': return 33;
    case 'e': return 35;
    case 'f': return 37;
    case 'g': return 38;
    case 'h': return 40;
    case 'i': return 42;
    case 'j': return 43;
    case 'k': return 27;
    case 'l': return 25;
    case 'm': return 24;
    case 'n': return 23;
    case 'o': return 21;
    case 'p': return 20;
    case 'q': return 18;
    case 'r': return 17;
    case 's': return 15;
    case 't': return 13;
    case 'u': return 11;
    case 'v': return 9;
    case 'w': return 7;
    case 'x': return 6;
    case 'y': return 4;
    case 'z': return 1;  
  }
}

// next bit was also on reddit.

void message(const char *str) {
 FastLED.clear();
  while (*str) {
    if (isAlpha(*str)) {
      auto i = getIndex(*str);

      leds[i] = CHSV(random8(),255,255);
      FastLED.show();
      delay(1000);

      leds[i] = CRGB::Black;
      FastLED.show();
      delay(700);
    }
    else if (isSpace(*str)) {
      delay(500);
    }

    str++;
  }
  delay(4300);
}

void setup(){
  FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); //setting up the FastLED
  Serial.begin(9600); //seeds the RNG
  randomSeed(analogRead(0));
    }

void loop(){
 
  switch(z){
   case 0:
   here();
   break;
  case 1:
   flee();
   break;
  case 2:
   help();
   break;
  case 3:
   fader();
   break; 
  case 4: 
   merry();
   break;
  case 5:
   justice();
   break;
  default:
   normal();
   break;
  }

  z = random (0, 9); // random number for choosing the routine

}

void normal() {
  FastLED.clear();
  {
    for(int i = 0; i < NUM_LEDS; i++ )
      {
        leds[i] = CHSV(random8(),255,255);
      }
  FastLED.show(); 
  delay(5000);
  }
}  

void merry() {
message("merry christmas");     
}

void fader() {
FastLED.clear();
 for(int t= 0; t < 11; t++ ){
 for(int i = 0; i < NUM_LEDS; i++ )
   {
   leds[i].setRGB(0,255,0); 
   leds[i].fadeLightBy(brightness);
  }
  FastLED.show();
  brightness = brightness + fadeAmount;
  // reverse the direction
  if(brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount ; 
  }     
delay(5);
}
}

void here() {
message("im right here"); 
}

void flee() {
message("run run run");
}

void help() {
message("help help");
}

void justice(){
  message("justice for mews");
}

