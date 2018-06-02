#include "SoilMoisture.hpp"

#include <Arduino.h>

SoilMoisture::SoilMoisture(const uint8_t analog_pin) :
  AnalogSensor(analog_pin)
{
}

float SoilMoisture::read(void)
{
    float v;
    v = AnalogSensor::read(FROM_LOW, FROM_MAX, TO_MIN, TO_MAX);
    Serial.print("[INFO] soil_moisture: ");
    Serial.println(v);
    return v;
}
