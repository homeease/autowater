#include "SunSensor.hpp"

#include <Arduino.h>

SunSensor::SunSensor(const uint8_t analog_pin) :
  AnalogSensor(analog_pin)
{
}

// Return percentage of darkness
float SunSensor::read(void)
{
    float v;
    v = AnalogSensor::read(FROM_LOW, FROM_MAX, TO_MIN, TO_MAX);
    Serial.print("[INFO] sun_sensor darkness: ");
    Serial.println(v);
    return v;
}
