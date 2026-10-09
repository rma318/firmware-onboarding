#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"
void setup()
{
    Serial.begin(115200);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("Failed to initialize BME280 sensor");
    }
    // Code here!
}

void loop()
{
    float temperatureC = BMEI2CInterfaceInstance::instance().readTemperature();
    LEDControllerInstance::instance().update(temperatureC, millis());
    bool on = LEDControllerInstance::instance().isBlinking();
    digitalWrite(BMEConstants::LED_PIN, on ? HIGH : LOW);
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.print(" C, LED is ");
    Serial.println(on ? "ON" : "OFF");
    // Code here!
}