#ifndef DISPLAYCONTROLLER_h
#define DISPLAYCONTROLLER_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include "LedControl.h" // https://playground.arduino.cc/Main/LedControl


#define LED_DATA_IN_PIN   25
#define LED_CLK_PIN       22 
#define LED_LOAD_CS_PIN   23 
#define ONE_LED_DEVICE    1  


class DisplayController {
  public:
    DisplayController(){       
      display.shutdown(0,false);
      display.setIntensity(0,8);
      display.setLed(0,2,7,true);   
      //Led at row 0 second from left too
      display.setLed(0,0,1,true);   
      delay(500);
      //switch the first Led off (second one stays on)
      display.setLed(0,2,7,false);
    }
    inline void print(char *){}
  private:
    LedControl display = LedControl(LED_DATA_IN_PIN, LED_CLK_PIN ,LED_LOAD_CS_PIN, ONE_LED_DEVICE);

};

#endif
