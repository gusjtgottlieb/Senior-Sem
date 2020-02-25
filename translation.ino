#include "FastLED.h"
//#include <KeyboardController.h>

#define NUM_LEDS 24
#define DATA_PIN 5
#define w 119
#define s 115
#define a 97
#define d 100
#define x_max 12
#define y_max 1
int x = 0;
int y = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
  
  Serial.begin(9600);
  Serial.println();
  Serial.println("X: ");
  Serial.println(x);
  Serial.println("Y: ");
  Serial.println(y);
  Serial.println("Enter a command");

  leds[mapping(x, y)] = CRGB(0, 0, 255);
  FastLED.show();
  //delay(100);
  
}

int mapping(int x, int y) {
  int light;
  int parity;
  if (y % 2 == 0) {
    parity = 0;
  }
  else if (y % 2 == 1) {
    parity = 1;
  }

  if (parity == 0) {
    light = y * 12 + x;
  }
  else if (parity == 1) {
    light = (y * 12 - 1) + (12 - x);
  }

  return light;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    leds[mapping(x, y)] = (0, 0, 0);
    int comm = Serial.read();
    if (comm == w) {
      if (y == y_max) {
      }
      else {
        y += 1;
      }
    }
    else if (comm == a) {
      if (x == 0) {
      }
      else {
        x -= 1;
      }
    }
    else if (comm == s) {
      if (y == 0) {
      }
      else {
        y -= 1;
      }
    }
    else if (comm == d) {
      if (x == x_max) {
      }
      else {
        x += 1;
      }
    }
    
    Serial.println("X: ");
    Serial.println(x);
    Serial.println("Y: ");
    Serial.println(y);
    Serial.println("Enter a command");

    FastLED.show();
    leds[mapping(x, y)] = CRGB(0, 0, 255);
    FastLED.show();
    //delay(100);
  }
  
//  for (int i = 0; i < 12; i++) {
//    for (int j = 0; j < 12; j++) {
//      int light = mapping(j, i);
//      leds[light] = CHSV(0, 0, 255);
//      FastLED.show();
//      delay(100);
//    }
//  }
//
//  
//  int i = mapping(11, 1);
//  leds[i] = CHSV(255, 255, 255);
//  FastLED.show();
//
//  int j = mapping(11, 0);
//  leds[j] = CHSV(0, 255, 255);
//  FastLED.show();
//
//  int l = mapping(0, 1);
//  leds[l] = CHSV(0, 0, 255);
//  FastLED.show();
//
//  int k = mapping(0, 0);
//  leds[k] = CHSV(0, 0, 255);
//  FastLED.show();
}
