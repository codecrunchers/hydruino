#include "Sensor.h"

Sensor::Sensor(){}

void Sensor::init(char *desc, int pin){
  strncpy(_desc,desc,255);
  PIN = pin;
  pinMode(PIN, INPUT);
}

float Sensor::readValue(){
  setLastValue(analogRead(PIN));
  return lastVal;
}
