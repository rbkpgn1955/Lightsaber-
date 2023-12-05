#include <FastLED.h>
#define numLED 30     // 100 leds/meter
#define pinLED 2      // pin D2
#define lumLED 225    // STRIP BRIGHTNESS [0 - 255]
#define satLED 255    // SATURATION [pale (0) - full (255)]
CRGB leds[numLED];
int hueLED;

// hue colors
#define RED 0
#define ORA 32
#define YEL 64
#define GRE 96
#define AQU 128
#define BLU 160
#define PUR 192
#define PIN 224

// switches
#define pinBUT 4      // pin D4 pulldown button
int colorState = 0;   // switch counter
int button = 0;

// GY521 module
#define pinSCL A5     // pin A5 SCL
#define pinSDA A6     // pin A6 SDA

void setup() {
  delay(2000);        // delay when uploading and disconnecting
  Serial.begin(9600); // before leds draw lots of current

  FastLED.addLeds<WS2812B, pinLED, GRB>(leds, numLED);
  FastLED.setBrightness(lumLED);
  hueLED = RED;
  colorCycle(hueLED);

  pinMode(pinBUT, INPUT);
}

void loop() {

  // button pressing
  if(colorState > 4){ colorState = 0; } // reset color counter
  button = digitalRead(pinBUT);
  if(button == HIGH){
    colorState += 1;
  }

  // change saber color bc button pressed
  switch(colorState){
    case 0:
      hueLED = RED;
      break;
    case 1:
      hueLED = BLU;
      break;
    case 2:
      hueLED = PUR;
      break;
    case 3:
      hueLED = GRE;
      break;
    case 4:
      hueLED = YEL;
      break;
  }
  colorCycle(hueLED);     // light that shit up

  //do the test things
  flicker(4);
  flicker(6);
  flicker(14);
  flicker(16);
  
  FastLED.show();
  FastLED.delay(750);     // doesn't need to flicker all the damn time
}


// change dem colorss
void colorCycle(int hue){
  for (int k=0; k<numLED; ++k){
    leds[k] = CHSV(hue, satLED, lumLED);
  }
  FastLED.show();
}


// flickering lighting effects
// aka brightness control

// test - flicker the leds before and after a given index
void flicker (byte numled){
  CHSV statics0 = CHSV(hueLED, satLED, lumLED-100);
  CHSV statics1 = CHSV(hueLED, satLED, lumLED+30);
  leds[numled-1]=statics0;
  leds[numled+1]=statics1;
  FastLED.show();
  FastLED.delay(80);
  leds[numled+1]=statics0;
  leds[numled-1]=statics1;
  FastLED.show();
  FastLED.delay(50);
}
