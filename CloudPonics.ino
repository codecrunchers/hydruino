#include "nutrient_pump.h"
#include "water_pump.h"
#include "Fan.h"

Fan fan = Fan();
NutrientPump nutrient_pump = NutrientPump();
WaterPump water_pump = WaterPump();

void setup() {
  init_controllers();
}

void loop() {
  // put your main code here, to run repeatedly:

}



void init_controllers(){
  nutrient_pump.init();
  water_pump.init();
  fan.init("fan controller", FAN_RELAY_PIN);

}
