#include "MotorController.h"

MotorController::MotorController(){}

void MotorController::stop(){
  digitalWrite(relayPin, LOW);    
}

void MotorController::start(){
   digitalWrite(relayPin, HIGH);    
}

