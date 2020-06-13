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
using Effect = void(*)(CRGB*, uint, uint);

#define DEBUG 1
#define RELEASE 0

#define BUILD 0

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
public:
    CRGB leds[NUM_LEDS];
    UINT num_leds;
    UINT led_pointer;
    UINT line_length;
    BOOL begined = false;

public:
    void draw(char, CRGB);
    void drawString(String, CRGB);

    void draw(char, Effect);
    void drawString(String, Effect);

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
    void drawBlind(void);
    void fill(CRGB, uint, uint);

    void drawZero(Effect);
    void drawOne(Effect);
    void drawTwo(Effect);
    void drawThree(Effect);
    void drawFour(Effect);
    void drawFive(Effect);
    void drawSix(Effect);
    void drawSeven(Effect);
    void drawEight(Effect);  
    void drawNine(Effect);
    void drawDb(Effect);
    void fill(Effect, uint, uint);
};

class CButton
{   
private:
    static CButton* last;
    static CButton* first;
    static CButton* button;

    int prev_state = 0;
    int state = 0;
    int pin = -1;
    CButton* next = nullptr;

public:
    static void Tick();

    CButton(int);

    bool isPressed(void);
    bool isReleased(void);
    void update(void);
};

extern CDigitLED DigitLED;

#endif
