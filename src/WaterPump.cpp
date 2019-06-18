#include "WaterPump.h"

void WaterPump::stop(){
  _debugWrite("Stop Motor on Pin");
  _debugWrite(Sensor::getPin());  
  digitalWrite(WATER_PUMP_RELAY_PIN, LOW);    
}

void WaterPump::start(){
  _debugWrite("Start Motor");
   digitalWrite(WATER_PUMP_RELAY_PIN, HIGH);    
}



