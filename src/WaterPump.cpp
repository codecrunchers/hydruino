#include "WaterPump.h"

void WaterPump::stop()
{
  _debugWrite("Stop Motor on Pin");
  //_debugWrite(Sensor::getPin());
  if (EMULATE_SENSOR)
  {
    Serial.println("Emulating motor stop");
  }
  else
  {
    digitalWrite(WATER_PUMP_RELAY_PIN, LOW);
  }
}

void WaterPump::start()
{
  if (EMULATE_SENSOR)
  {
    Serial.println("Emulating motor start");
  }
  else
  {
    digitalWrite(WATER_PUMP_RELAY_PIN, HIGH);
  }
}
