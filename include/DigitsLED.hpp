#ifndef DIGIT_LED_HPP
#define DIGIT_LED_HPP

#include <FastLED.h>

#define LEDS_AT_LINE 6
#define LINES_AMOUNT 7
#define DIGITS_COUNT 4
#define LEDS_PER_DOT 2
#define DOTS_AMOUNT  2

#define LED_DATA_PIN 10
#define NUM_LEDS ((LEDS_AT_LINE * LINES_AMOUNT * DIGITS_COUNT) + (LEDS_PER_DOT * DOTS_AMOUNT))

using uint = int;
using UINT = unsigned int;
using BOOL = bool;

#define DEBUG 1
#define RELEASE 0

#define BUILD RELEASE

#if BUILD == DEBUG

    #define __SERIAL_BEGIN(x) Serial.begin(x)
    #define __PRINTLN(x) Serial.println((x))
    #define __PRINT(x) Serial.print((x))

#elif BUILD == RELEASE

    #define __SERIAL_BEGIN(x)
    #define __PRINTLN(x)
    #define __PRINT(x)

#endif

class CDigitLED
{
    CRGB leds[NUM_LEDS];
    UINT num_leds;
    UINT led_pointer;
    UINT line_length;
    BOOL begined = false;

public:
    void draw(char, CRGB);
    void drawString(String, CRGB);
    void begin();

private:
    void drawZero(CRGB);
    void drawOne(CRGB);
    void drawTwo(CRGB);
    void drawThree(CRGB);
    void drawFour(CRGB);
    void drawFive(CRGB);
    void drawSix(CRGB);
    void drawSeven(CRGB);
    void drawEight(CRGB);  
    void drawNine(CRGB);
    void drawDb(CRGB);
    void fill(CRGB, uint start, uint end);
};

extern CDigitLED DigitLED;

#endif
