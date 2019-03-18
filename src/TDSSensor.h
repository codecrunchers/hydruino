#ifndef TDSSENSOR_h
#define TDSSENSOR_h

#include "Sensor.h"
class TDSSensor : public Sensor {
  public:
    TDSSensor(sensor_type t) : Sensor(t){}
};

#endif

