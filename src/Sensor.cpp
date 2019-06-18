#include "Sensor.h"

Sensor::~Sensor()
{
  if (_desc != nullptr)
  {
    delete[] _desc;
  }
}

void Sensor::init(const char *desc, int8_t pin)
{
  setDesc(desc);
  setPin(pin);
  if (DEBUG)
  {
    Serial.println("------");
    Serial.print("recd: ");
    Serial.println(pin);
    Serial.print("stored: ");
    Serial.println(getPin());
    Serial.println("------");
  }
  pinMode(pin, INPUT);
}

float Sensor::readValue()
{
  switch (getSensorType())
  {
  case ANALOG_SENSOR:
    return readValueAnalog();
  case DIGITAL_SENSOR:
    return readValueDigital();
  default:
    return -1L;
  }
}

float Sensor::readValueAnalog()
{
  _debugWrite("Analog Read");
  setLastValue(analogRead(getPin()));
  return getLastValue();
}

float Sensor::readValueDigital()
{
  _debugWrite("Digital Read");
  setLastValue(digitalRead(getPin()));
  return getLastValue();
}
