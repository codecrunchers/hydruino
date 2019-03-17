#ifndef NUTRIENTPUMP_h
#define NUTRIENTPUMP_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include "cloudponics.h"


class NutrientPump {
  public:
    NutrientPump();
    
    void init();
    void ph_up(int dosage);
    void ph_down(int dosage);

 
  private:
    const int PH_UP_PUMP_RELAY   = PH_UP_PUMP_RELAY_PIN;
    const int PH_DOWN_PUMP_RELAY  = PH_DOWN_PUMP_RELAY_PIN;
    void stop();

};

#endif
