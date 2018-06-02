#ifndef SOIL_MOISTURE_HPP
#define SOIL_MOISTURE_HPP

#include <Arduino.h>
#include "AnalogSensor.hpp"

extern "C" {
#include <inttypes.h>
}

class SoilMoisture : public AnalogSensor
{
  public:
    const static long FROM_LOW = 344; // Lowest analog value
    const static long FROM_MAX = 310; // Highest analog value
    const static long TO_MIN = 0; // Lowest float value
    const static long TO_MAX = 100; // Highest float value

    SoilMoisture(const uint8_t analog_pin);
    float read(void);
};

#endif
