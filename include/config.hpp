#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include <RTC.h>
#include <DigitsLED.hpp>

using BYTE = byte;
using STRING = String;

#define LEDS_DATA_PIN   10
#define RTC_SCLK_PIN    6
#define RTC_DAT_PIN     7
#define RTC_RST_PIN     8 
#define BUTTON1_PIN     2
#define BUTTON2_PIN     3
#define BUTTON3_PIN     5

#define TIME_UPDATE_DELAY 1000

#endif 