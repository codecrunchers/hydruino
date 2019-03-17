#include "MotorController.h"

MotorController::MotorController(){}

void MotorController::init(char *desc, int pin){
  RELAY = pin;
  for(int i=0; i < 256 ;i++){
    _desc[i] = ++desc;
  }
}

void MotorController::stop(){
  digitalWrite(RELAY, LOW);    
}

void MotorController::start(){
   digitalWrite(RELAY, HIGH);    
}

