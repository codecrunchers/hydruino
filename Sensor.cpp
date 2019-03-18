#include "Sensor.h"

Sensor::Sensor(){}

void Sensor::init(char *desc, int pin){
  PIN = pin;
  pinMode(PIN, INPUT);
}

float Sensor::readValue(){
  setLastValue(analogRead(PIN));
  return lastVal;
}
