#ifndef ANALOG_SENSOR_HPP
#define ANALOG_SENSOR_HPP

#include <Arduino.h>

extern "C" {
#include <inttypes.h>
}

class AnalogSensor
{
  public:
    AnalogSensor(const uint8_t analog_pin);
    float read(const long from_low, const long from_max, const long to_min, const long to_max);

  private:
    uint8_t m_analog_pin;
};

#endif
