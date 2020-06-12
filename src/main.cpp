#include <config.hpp>

RTC rtc
(
  RTC_DS1302,
  RTC_RST_PIN,
  RTC_SCLK_PIN,
  RTC_DAT_PIN
);
STRING Time = "12:10";

void setup() 
{
  Serial.begin(9600);
  DigitLED.begin();
  rtc.begin();
}

bool inverse = 0;
byte counter = 0;
void TimeScaler(CRGB* leds, uint start, uint end)
{
  for(int i = start; i < end; i++){
    leds[i] = CRGB(192, 0, 248);
  }
}

CRGB color;
void loop() 
{
  for (int i = 0 ; i < NUM_LEDS; i++)
  {
    color = CHSV(counter + i * 2, 255, 255);
    DigitLED.drawString(rtc.gettime("H:i"), color);
    delay(i);
  }
  counter++;
  for (int i = NUM_LEDS-1 ; i >= 0; i--)
  {
    color = CHSV(counter + i * 2, 255, 255);
    DigitLED.drawString(rtc.gettime("H:i"), color);
    delay(i);
  }
  counter++;
}