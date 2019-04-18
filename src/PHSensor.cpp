#include "PHSensor.h"

PHSensor::PHSensor(sensor_type t)  : Sensor(t) {
    _debugWrite("Init PH");
//  ph.begin();
}

PHSensor::~PHSensor(){}

float PHSensor::readValue(float temperature){
  voltage = Sensor::readValue()/1024.0*5000;  // read the voltage
  phValue = ph.readPH(voltage,temperature); // convert voltage to pH with temperature compensation
  return phValue;
}


