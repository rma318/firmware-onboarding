#include "LEDController.h"
void LEDController::update(float temperatureC, uint32_t nowMs)
{
    if (temperatureC < BMEConstants::MIN_TEMP_C) temperatureC = BMEConstants::MIN_TEMP_C;
    if (temperatureC > BMEConstants::MAX_TEMP_C) temperatureC = BMEConstants::MAX_TEMP_C;

    float fraction = (temperatureC - BMEConstants::MIN_TEMP_C) / (BMEConstants::MAX_TEMP_C - BMEConstants::MIN_TEMP_C);
    float slow = BMEConstants::SLOW_INTERVAL_MS;
    float fast = BMEConstants::FAST_INTERVAL_MS;
    float interval = slow + (fast - slow) * fraction;
    
    if (nowMs - lastBlinkTime >= (uint32_t)interval)
    {
        isBlinkingstate = !isBlinkingstate; // Toggle the blinking state
        lastBlinkTime = nowMs; // Update the last blink time
    }
}

bool LEDController::isBlinking() const
{
    return isBlinkingstate;
}
