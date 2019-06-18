#ifndef MOTORCONTROLLER_h
#define MOTORCONTROLLER_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "cloudponics.h"
#include "Sensor.h"

class MotorController : public Sensor {

  public:
    MotorController(sensor_type t) : Sensor(t){}
    
    void init(const char *desc, int8_t pin) override;
    float readValue() override ;   //defaults to Temperature

    inline virtual void stop(){}
    inline virtual void start(){}    

    
    
};

#endif
