#include <config.hpp>

CRGB leds[NUM_LEDS];
BYTE counter;
RTC rtc
(
  RTC_DS1302,
  RTC_RST_PIN,
  RTC_SCLK_PIN,
  RTC_DAT_PIN
);

void setup() 
{
   __SERIAL_BEGIN(9600);

  FastLED.addLeds<WS2812B, LEDS_DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(50);

  rtc.begin();
}

int i;
String time;
void loop() 
{
  time = rtc.gettime("s");
  
  int pos = 0;
  for(int i = DIGITS_COUNT - 1; i >= 0; i--)
  {
    draw(time[i], pos++, CRGB::Purple);
  }

  FastLED.show();

  delay(1000);
}

inline void fill(CRGB color, int start, int end) {
  for (int i = start; i < end; leds[i++] = color);
}

void draw(char num, int pos , CRGB color)
{
  switch (num)
  {
  case '0':
    drawZero(pos, color);
    break;
  case '1':
    drawOne(pos, color);
    break;
  case '2':
    drawTwo(pos, color);
    break;
  case '3':
    drawThree(pos, color);
    break;
  case '4':
    drawFour(pos, color);
    break;
  case '5':
    drawFive(pos, color);
    break;
  case '6':
    drawSix(pos, color);
    break;
  case '7':
    drawSeven(pos, color);
    break;
  case '8':
    drawEight(pos, color);
    break;
  case '9':
    drawNine(pos, color);
    break;
  case ':':
    drawDb(pos, color);
    break;
  }
}

void drawZero(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3));
  fill(CRGB(0, 0, 0),(pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawOne(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawTwo(int pos, CRGB color)
{
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawThree(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawFour(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawFive(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawSix(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 5), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawSeven(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 4), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 6));      
}
void drawEight(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawNine(int pos, CRGB color)
{
  fill(color, (pos * NUM_LEDS_PER_DIGIT), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2));
  fill(CRGB(0, 0, 0), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 2), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3));
  fill(color, (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 3), (pos * NUM_LEDS_PER_DIGIT + LINE_LENGTH * 7));
}
void drawDb(int pos, CRGB color)
{

}