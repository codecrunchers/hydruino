// CLOUDPONICS.h

#ifndef CLOUDPONICS_h
#define CLOUDPONICS_h

#define ANALOG_SENSOR 1
#define DIGITAL_SENSOR 2

namespace {
  const int8_t DEBUG             = 1;
  const int8_t HOW_BRIGHT        = 10;


  const int16_t MAIN_LOOP_INTERVAL = 500;
  const int8_t LED_DATA_IN_PIN   = 7;
  const int8_t LED_CLK_PIN       = 5;
  const int8_t LED_LOAD_CS_PIN   = 6; 
  const int8_t PH_UP_PUMP_RELAY_PIN  =  9;   //PWM
  const int8_t PH_DOWN_PUMP_RELAY_PIN =  10;  //PWM
  const int8_t WATER_PUMP_RELAY_PIN    =  1;
  const int8_t FAN_RELAY_PIN           =  2;
  const int8_t DHT11_PIN              =  3;
  const int8_t LDR_PIN                 =  A1;
  const int8_t TDS_PIN                = A2;
}

#endif
