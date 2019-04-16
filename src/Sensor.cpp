#include "Sensor.h"


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
  #ifdef DEBUG
    Serial.println("\r\nAnalog Read");
  #endif
  setLastValue(analogRead(getPin()));
  return getLastValue();

}

float Sensor::readValueDigital(){
  #ifdef DEBUG
    Serial.println("\r\nDigital Read");
  #endif

  setLastValue(digitalRead(getPin()));
  return getLastValue();

}

