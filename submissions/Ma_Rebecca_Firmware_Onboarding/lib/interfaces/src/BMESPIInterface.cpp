#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() : bme(BMEConstants::SPI_CS_PIN) {}

bool BMESPIInterface::begin()
{
    if (!bme.begin())
    {
        return false;
    }
    connected = true;
    return true;
}

float BMESPIInterface::readTemperature()
{
    if (connected)
    {
        lastTemperature = bme.readTemperature();
    }
    
    return lastTemperature;
}

