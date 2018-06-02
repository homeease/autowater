#ifndef SUN_SENSOR_HPP
#define SUN_SENSOR_HPP

#include "AnalogSensor.hpp"

extern "C" {
#include <inttypes.h>
}

class SunSensor : public AnalogSensor
{
  public:
    const static long FROM_LOW = 35; // Lowest analog value
    const static long FROM_MAX = 860; // Highest analog value
    const static long TO_MIN = 0; // Lowest float value
    const static long TO_MAX = 100; // Highest float value

    SunSensor(const uint8_t analog_pin);
    float read(void);
};

#endif
