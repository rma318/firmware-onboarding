#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class LEDController
{
public:
 LEDController() = default;

 void update(float temperatureC, uint32_t nowMs);
 bool isBlinking() const;

 // Code here!
private:
    bool isBlinkingstate = false; // Flag to indicate if the LED is currently blinking
    uint32_t lastBlinkTime = 0; // Timestamp of the last blink


 // Code here!
};
using LEDControllerInstance = etl::singleton<LEDController>;