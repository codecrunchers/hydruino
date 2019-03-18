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
    
    inline virtual void init(char *desc, int pin) {
      strncpy(_desc, desc, 255);
      relayPin = pin;
    }

    inline virtual void stop();
    inline virtual void start();    

  private:
    char _desc[256];
    int relayPin;
};

#endif
