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

//#define DEBUG


class Sensor {

  public:
    typedef int sensor_type;
    Sensor(sensor_type type) : _sensor_type(type) { }
    int getPin() { return PIN;  }
    sensor_type getSensorType() { return _sensor_type; }
    float getLastValue(){ return lastVal; }

    virtual void init(char *desc, int pin);
    virtual float readValue();

  protected:
    inline void setPin(int pin){ PIN = pin; }
    inline void setDesc(char* desc){ strncpy(_desc, desc, 255);  }
    inline void setLastValue(float newValue){ lastVal = newValue; }


  private:
    sensor_type _sensor_type;
    char _desc[256];
    int PIN;
    float lastVal= 0L;
    float readValueAnalog();
    float readValueDigital();



};

#endif
