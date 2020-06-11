#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <Arduino.h>
#include <RTC.h>
#include <DigitsLED.hpp>

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

using BYTE = byte;
using STRING = String;

#define LEDS_DATA_PIN   10
#define RTC_SCLK_PIN    6
#define RTC_DAT_PIN     7
#define RTC_RST_PIN     8 

#define TIME_UPDATE_DELAY 1000

#endif 