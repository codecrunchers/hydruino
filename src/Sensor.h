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
    inline Sensor(sensor_type type) : _sensor_type(type) { }
    inline int getPin() { return PIN;  }
    inline sensor_type getSensorType() { return _sensor_type; }
    inline getLastValue(){ return lastVal; }

    virtual void init(char *desc, int pin);
    virtual float readValue();

  protected:
    void setPin(int pin){ PIN = pin; }
    void setDesc(char* desc){ strncpy(_desc,desc,255);  }
    void setLastValue(float newValue){ lastVal = newValue; }


  private:
    sensor_type _sensor_type;
    char _desc[256];
    int PIN;
    float lastVal= 0L;
    float readValueAnalog();
    float readValueDigital();



};

#endif
