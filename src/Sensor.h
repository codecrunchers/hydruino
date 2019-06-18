#ifndef SENSOR_h
#define SENSOR_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include "cloudponics.h"

class Sensor
{

public:
  typedef int8_t sensor_type;
  Sensor(sensor_type type) : _sensor_type(type) {}
  ~Sensor();
  int8_t getPin() { return _pin; }
  sensor_type getSensorType() { return _sensor_type; }
  float getLastValue() { return lastVal; }

  virtual void init(const char *desc, int8_t pin);
  virtual float readValue();
  inline char *getDesc()
  {

    return _desc;
  }

private:
  sensor_type _sensor_type;
  char *_desc = nullptr;
  int8_t _pin = 0;
  float lastVal = 0L;
  float readValueAnalog();
  float readValueDigital();

protected:
  inline void setPin(int8_t pin)
  {
    _pin = pin;
  }
  inline void setDesc(const char *desc)
  {
#ifndef NEW_H
    _debugWrite("Error no mem manager");
    return;
#else
    _desc = new char[256];
    strncpy(_desc, desc, 256);
#endif
  }
  inline void setLastValue(float newValue) { lastVal = newValue; }
};

#endif
