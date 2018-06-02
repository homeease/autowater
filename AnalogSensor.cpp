#include "AnalogSensor.hpp"

#include <Arduino.h>

AnalogSensor::AnalogSensor(const uint8_t analog_pin) :
  m_analog_pin(0)
{
  m_analog_pin = analog_pin;
}

float AnalogSensor::read(const long from_low, const long from_max, const long to_min, const long to_max)
{
    float output;
    uint16_t v;
    v = analogRead(m_analog_pin);
    output = map(v, from_low, from_max, to_min, to_max);
    return output;
}
