#include "BMEI2CInterface.h"


bool BMEI2CInterface::begin()
{
    if (!bme.begin(BMEConstants::I2C_ADDRESS))
    {
        return false;
    }
    connected = true;
    return true;
}

float BMEI2CInterface::readTemperature()
{
    if (connected)
    {
        lastTemperature = bme.readTemperature();
    }
   
    return lastTemperature;
}
