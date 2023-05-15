#include <FastLED.h>

#define BACK_NUM_LEDS   21
#define HEAD_NUM_LEDS    8

#define BACK_LED_PIN     4
#define HEAD_LED_PIN     6

CRGB back_leds[BACK_NUM_LEDS];
CRGB head_leds[HEAD_NUM_LEDS];

CRGB rgb_blue_color = CRGB(137, 215, 175);

void setup() {
  FastLED.addLeds<WS2812B, BACK_LED_PIN, GRB>(back_leds, BACK_NUM_LEDS);
  FastLED.addLeds<WS2812B, HEAD_LED_PIN, GRB>(head_leds, HEAD_NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  FastLED.clear();
  
  do_test_color();
  
  FastLED.show();
}

void do_test_color() {
  fill_rainbow(back_leds, BACK_NUM_LEDS, 0, 255 / BACK_NUM_LEDS);
  fill_solid(head_leds, HEAD_NUM_LEDS, rgb_blue_color);
}
