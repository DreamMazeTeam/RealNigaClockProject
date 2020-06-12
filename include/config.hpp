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

#define TIME_UPDATE_DELAY 1000

#endif 