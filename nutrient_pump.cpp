#include "nutrient_pump.h"

NutrientPump::NutrientPump(){}


void NutrientPump::init(){
 pinMode(PH_DOWN_PUMP_RELAY, OUTPUT);
 pinMode(PH_UP_PUMP_RELAY, OUTPUT);
}

void NutrientPump::ph_up(int dosage){
  analogWrite(PH_UP_PUMP_RELAY, dosage);    
  stop();
}
void NutrientPump::ph_down(int dosage){
  analogWrite(PH_DOWN_PUMP_RELAY, dosage);    
  stop();
}

