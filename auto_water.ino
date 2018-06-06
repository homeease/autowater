#include "SoilMoisture.hpp"
#include "SunSensor.hpp"
#include <Servo.h>

const static float MIN_SOIL_MOISTURE = 30.00;
const static float MIN_SUN_SENSOR_DARKNESS = 60.00;
const static uint8_t SERVO_PIN = 9;
const static uint16_t SERVO_START_POS = 90;
const static uint16_t SERVO_CLOSE_POS = SERVO_START_POS;
const static uint16_t SERVO_OPEN_POS = 0;
const static uint16_t WATERING_CHECK_INTERVAL = 1000; // ms

SoilMoisture soil_moisture(A0);
SunSensor sun_sensor(A1);
Servo myservo;
bool watering = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(SERVO_CLOSE_POS);
  delay(2000);
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
  return v > MIN_SUN_SENSOR_DARKNESS;
}
bool need_to_water(void)
{
  bool stat = true;
  stat &= soil_moisture_vote();
  stat &= sun_sensor_vote();
  return stat;
}

void start_watering(void)
{
  myservo.write(SERVO_OPEN_POS);
}

void stop_watering(void)
{
  myservo.write(SERVO_CLOSE_POS);
}

void loop() {
  bool stat = need_to_water();

  // if need to water then water otherwise
  // only stop watering if we were watering
  // and we no longer need to water
  if(!watering && stat)
  {
    start_watering();
    watering = true;
  }
  else if(watering && !stat)
  {
    stop_watering();
    watering = false;
  }

  delay(WATERING_CHECK_INTERVAL);
}
