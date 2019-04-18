#ifndef PHSENSOR_H_
#define PHSENSOR_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include "Sensor.h"
#include "DFRobot_PH.h"
#include <EEPROM.h>

class PHSensor : public Sensor {
  public:
    PHSensor(sensor_type t);
    ~PHSensor();
    float readValue(float temperature);
 
  private:
    float voltage;
    float phValue;
    DFRobot_PH ph;
};

#endif
