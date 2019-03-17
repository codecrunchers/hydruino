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

class MotorController {

  public:
    MotorController();
    
    void init(char* desc, int pin);
    void stop();
    void start();    

 
  private:
    char _desc[256];
    int RELAY;
};

#endif
