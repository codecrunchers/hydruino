#ifndef CLOUDPONICSH_
#define CLOUDPONICSH_

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include "pins_arduino.h"
  #include "WConstants.h"
#endif

#include <new.h>

namespace {
  const int8_t ANALOG_SENSOR = 1;
  const int8_t DIGITAL_SENSOR = 2;
  const int16_t DHT_WAIT_TIME = 1000;
  const bool DEBUG                  = true;;
  const int8_t HOW_BRIGHT             = 10;


  const int16_t MAIN_LOOP_INTERVAL    = 10000;
  const int8_t LED_DATA_IN_PIN        = 7;
  const int8_t LED_CLK_PIN            = 5;
  const int8_t LED_LOAD_CS_PIN        = 6; 
  const int8_t PH_UP_PUMP_RELAY_PIN   =  9;   //PWM
  const int8_t PH_DOWN_PUMP_RELAY_PIN =  10;  //PWM
  const int8_t WATER_PUMP_RELAY_PIN   =  7;
  const int8_t FAN_RELAY_PIN          =  2;
  const int8_t DHT11_PIN              =  3;
  const int8_t LDR_PIN                =  A1;
  const int8_t TDS_PIN                =  A2;
  const int8_t PH_PIN                =  A0;

  void _debugWrite(const char* msg){
    if(DEBUG){
      Serial.println(msg);
    }
  }
}

#endif
