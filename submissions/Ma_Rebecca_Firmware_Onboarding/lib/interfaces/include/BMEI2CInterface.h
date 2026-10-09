#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool begin();
    float readTemperature();
    // Code here!
private:
    Adafruit_BME280 bme; // BME280 sensor object
    bool connected = false; // Flag to indicate if the sensor is connected
    float lastTemperature = 0.0f; // Store the last read temperature value
    // Code here!
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;