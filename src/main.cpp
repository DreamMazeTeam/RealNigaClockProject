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
   __SERIAL_BEGIN(9600);

  DigitLED.begin();

  rtc.begin();

}

void loop() 
{
  Time = rtc.gettime("i:s");
  DigitLED.drawString(Time, CRGB::Purple);
  delay(1000);
}
