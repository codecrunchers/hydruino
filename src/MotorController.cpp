#include "MotorController.h"

void MotorController::init(const char *desc, int8_t pin) {
      Sensor::init(desc, pin);
      pinMode(pin, OUTPUT);//TODO - sublass
}

float MotorController::readValue(){
  //do not call me
  return -1L;
}

