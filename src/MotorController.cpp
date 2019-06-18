#include "MotorController.h"

void MotorController::init(const char *desc, int pin) {
      Sensor::init(desc, pin);
      pinMode(pin, OUTPUT);//TODO - sublass
}

float MotorController::readValue(){
  //do not call me
  return -1L;
}

