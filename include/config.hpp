#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include <RTC.h>
#include <FastLED.h>

#define DEBUG 1
#define RELEASE 0

#define BUILD DEBUG

#if BUILD == DEBUG

    #define __SERIAL_BEGIN(x) Serial.begin(x)
    #define __PRINTLN(x) Serial.println((x))
    #define __PRINT(x) Serial.print((x))

#elif BUILD == RELEASE

    #define __SERIAL_BEGIN(x)
    #define __PRINTLN(x)
    #define __PRINT(x)

#endif

using BYTE = byte;
using STRING = String;
using Effect = void(*)(void);


#define DIGITS_COUNT            2
#define LINE_LENGTH             6
#define ADDITIONAL_LEDS_NUM     0

#define NUM_LEDS_PER_DIGIT (LINE_LENGTH *7)
#define NUM_LEDS ((NUM_LEDS_PER_DIGIT * DIGITS_COUNT) + ADDITIONAL_LEDS_NUM)

#define LEDS_DATA_PIN   10
#define RTC_SCLK_PIN    6
#define RTC_DAT_PIN     7
#define RTC_RST_PIN     8 

#define TIME_UPDATE_DELAY 1000

void draw(char, int, CRGB);
void drawZero(int, CRGB);
void drawOne(int, CRGB);
void drawTwo(int, CRGB);
void drawThree(int, CRGB);
void drawFour(int, CRGB);
void drawFive(int, CRGB);
void drawSix(int, CRGB);
void drawSeven(int, CRGB);
void drawEight(int, CRGB);
void drawNine(int, CRGB);
void drawDb(int, CRGB);

#endif 