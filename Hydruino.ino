#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"
#include "src/TDSSensor.h"
#include "src/WaterTempHumiditySensor.h"
#include "src/DisplayController.h"
#include "src/WaterPump.h"
#include "src/PHSensor.h"
#include "src/TThread.h"
#include <SoftTimer.h>


Sensor waterL = Sensor(DIGITAL_SENSOR);                                      
WaterPump motor = WaterPump(DIGITAL_SENSOR);

struct data_t {
  float roomTemp = 25.0L;
  float roomHumidity;
  bool waterLevelSwitchFiring = false;
  int8_t phLevel;
  float luxValue;
  float waterTemp;
  float waterHumidity;
  float fanFiring = false;
  float ledLampOn = false;
  float waterQuality;

} sensor_data;

int loopCount = 0;

void _main(Task *t);
Task mainLoop(MAIN_LOOP_INTERVAL, _main);
TThread motorLoop = TThread(&motor, 5000);

void setup() {
  Serial.begin(9600);
  init_controllers();
  SoftTimer.add(&mainLoop); 
  motorLoop.start();
}

void _main(Task* t) {
  Serial.println("In Pseudo Main Loop");  
}

void init_controllers(){
  motor.init("Pump", WATER_PUMP_RELAY_PIN);
}
