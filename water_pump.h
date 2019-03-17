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


class WaterPump {
  public:
    WaterPump();
    
    void init();
    void start();
    void stop();

 
  private:
    int pump_state = LOW;
    const int WATER_PUMP_RELAY   = WATER_PUMP_RELAY_PIN;

};

#endif
