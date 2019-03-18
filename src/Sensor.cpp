#include "Sensor.h"

Sensor::Sensor(){}

void Sensor::init(char *desc, int pin){
  setDesc(desc);
  setPin(pin);
  pinMode(PIN, INPUT);
}


float Sensor::readValue(){
  setLastValue(analogRead(PIN));
  return lastVal;
}
