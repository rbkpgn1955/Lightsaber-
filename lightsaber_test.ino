#include <FastLED.h>
#define data 2
#define num 1

CRGB leds[num];

void setup() {
  FastLED.addLeds<WS2812B, data>(leds, num);
  
}

void loop() {
  leds[0] = CRGB::White;
  FastLED.show();
  delay(100);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
