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

class Sensor {

  public:
    Sensor();

    virtual void init(char *desc, int pin);
    virtual float readValue();

    int getPin() { 
      return PIN;
    }


  private:
    char _desc[256];
    int PIN;
    float lastVal= 0L;

  protected:
    void setPin(int pin){
      PIN = pin;
    }

    void setDesc(char* desc){
      strncpy(_desc,desc,255);
    }

    void setLastValue(float newValue){
      lastVal = newValue;
    }
};

#endif
