#include "src/cloudponics.h"
#include "src/Sensor.h"
#include "src/PHSensor.h"
#include <SoftTimer.h>

PHSensor ph = PHSensor(ANALOG_SENSOR);

struct data_t {
  float roomTemp;
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

void _loop(Task *t);
Task mainLoop(MAIN_LOOP_INTERVAL, _loop);


void setup() {
  Serial.begin(9600);
  init_controllers();
  _debugWrite(ph.getDesc());
  SoftTimer.add(&mainLoop); 
}


void _loop(Task* t) {
  int phLevel = ph.readValue();
  Serial.println(phLevel);
}


void init_controllers(){
  ph.init("PH", PH_PIN);
  _debugWrite("Initted");
}
