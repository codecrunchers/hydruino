#include "Sensor.h"

Sensor::~Sensor(){
  if(_desc != nullptr){
    delete  [] _desc;
  }
}


void Sensor::init(const char *desc, int pin){
  setDesc(desc);
  setPin(pin);
  pinMode(getPin(), INPUT);
}


float Sensor::readValue(){
  switch(getSensorType()) {
    case ANALOG_SENSOR:
      return readValueAnalog();
    case DIGITAL_SENSOR:
      return readValueDigital();
    default:
      return -1L;
  }
}

float Sensor::readValueAnalog(){
   _debugWrite("Analog Read");
  setLastValue(analogRead(getPin()));
  return getLastValue();

}

float Sensor::readValueDigital(){
   _debugWrite("Digital Read");
  setLastValue(digitalRead(getPin()));
  return getLastValue();

}

