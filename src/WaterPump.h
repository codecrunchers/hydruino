#ifndef WATERPUMP_h
#define WATERPUMP_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "cloudponics.h"
#include "MotorController.h"


class WaterPump : public MotorController {
  public:
    inline WaterPump(sensor_type t) : MotorController(t){}
    void stop();
    void start();    
    

};

#endif
