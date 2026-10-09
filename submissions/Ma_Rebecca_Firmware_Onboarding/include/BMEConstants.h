#pragma once
#include <Arduino.h>
namespace BMEConstants
{
    constexpr uint8_t I2C_ADDRESS = 0x76; // I2C address of the BME280 sensor
    constexpr uint8_t SPI_CS_PIN = 10;   // SPI chip select pin for the BME280 sensor
    constexpr uint8_t LED_PIN = 7;        // Pin for the LED
    constexpr float MIN_TEMP_C = 20.0f;
    constexpr float MAX_TEMP_C = 35.0f;
    constexpr uint32_t SLOW_INTERVAL_MS = 500; // Slow interval in milliseconds
    constexpr uint32_t FAST_INTERVAL_MS = 50;  // Fast interval in milliseconds
 // constants here!
}