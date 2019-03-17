#include "water_pump.h"

WaterPump::WaterPump(){}


void WaterPump::init(){
  pinMode(WATER_PUMP_RELAY, OUTPUT);
}

void WaterPump::start(){
  digitalWrite(WATER_PUMP_RELAY, HIGH);    
  stop();
}

void WaterPump::stop(){
  digitalWrite(WATER_PUMP_RELAY, LOW);    
  stop();
}



