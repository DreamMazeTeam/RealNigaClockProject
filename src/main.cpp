#include <config.hpp>

RTC rtc
(
  RTC_DS1302,
  RTC_RST_PIN,
  RTC_SCLK_PIN,
  RTC_DAT_PIN
);

CButton btn_mode(BUTTON1_PIN);
CButton btn_up(BUTTON2_PIN);
CButton btn_down(BUTTON3_PIN);

void setup() 
{
  Serial.begin(9600);
  DigitLED.begin();
  rtc.begin();
}

String getOutput(void)
{
  return String(rtc.gettime("H:i"));
}

byte counter = 0;
CRGB color;

void loop() 
{
  CButton::Tick();
  delay(1000);

  for (int i = 0 ; i < NUM_LEDS; i++)
  {
    color = CHSV(counter + i * 2, 255, 255);
    DigitLED.drawString(getOutput(), color);
    delay(i);
  }
  counter++;
  for (int i = NUM_LEDS-1 ; i >= 0; i--)
  {
    color = CHSV(counter + i * 2, 255, 255);
    DigitLED.drawString(getOutput(), color);
    delay(i);
  }
  counter++;
}