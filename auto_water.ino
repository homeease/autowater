#include "SoilMoisture.hpp"
#include "SunSensor.hpp"

const static float MIN_SOIL_MOISTURE = 30.00;
const static float MIN_SUN_SENSOR_DARKNESS = 60.00;

SoilMoisture soil_moisture(A0);
SunSensor sun_sensor(A1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(2000);
  pinMode(LED_BUILTIN, OUTPUT);
}

bool soil_moisture_vote(void)
{
  float v;
  v = soil_moisture.read();
  Serial.print("[INFO] main Moisture: ");
  Serial.print(v);
  Serial.println("%");
  return v < MIN_SOIL_MOISTURE;
}

bool sun_sensor_vote(void)
{
  float v;
  v = sun_sensor.read();
  Serial.print("[INFO] main SunSensor: ");
  Serial.print(v);
  Serial.println("%");
  return v < MIN_SUN_SENSOR_DARKNESS;
}
bool need_to_water(void)
{
  bool stat = true;
  stat &= soil_moisture_vote();
  stat &= sun_sensor_vote();
  return stat;
}

void water(void)
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void loop() {
  // if need to water then water otherwise do nothing
  if(need_to_water())
  {
    water();
  }
  delay(1000);

}
