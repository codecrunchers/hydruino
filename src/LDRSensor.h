#ifndef LDRSENSOR_h
#define LDRSENSOR_h

#include "Sensor.h"
class LDRSensor : public Sensor {
  public:
    LDRSensor(sensor_type t) : Sensor(t){}
    char* status();
};

#endif

