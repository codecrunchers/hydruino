#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"
#include "src/TDSSensor.h"
#include "src/WaterTempHumiditySensor.h"
#include "src/DisplayController.h"
#include "src/PHSensor.h"
#include <SoftTimer.h>


DHTSensor extTempHmdSensor = DHTSensor(DIGITAL_SENSOR);
LDRSensor ldr = LDRSensor(ANALOG_SENSOR);
TDSSensor tdsSensor = TDSSensor(ANALOG_SENSOR);
WaterTempHumiditySensor wthSensor = WaterTempHumiditySensor(ANALOG_SENSOR);
Sensor waterL = Sensor(DIGITAL_SENSOR);                                      
DisplayController dc = DisplayController();
PHSensor ph = PHSensor(ANALOG_SENSOR);

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

void _loop(Task *t);
Task mainLoop(MAIN_LOOP_INTERVAL, _loop);


void setup() {
  Serial.begin(9600);
  init_controllers();
  dc.init(LED_DATA_IN_PIN, LED_CLK_PIN, LED_LOAD_CS_PIN, HOW_BRIGHT);
  SoftTimer.add(&mainLoop); 
}



void _loop(Task* t) {
  dc.busy(true); //set booting
  sensor_data.roomTemp = extTempHmdSensor.getTemperature();
  sensor_data.roomHumidity = extTempHmdSensor.getHumidity();
  sensor_data.luxValue = ldr.readValue();
  sensor_data.waterQuality = tdsSensor.readValue();
  sensor_data.waterTemp = wthSensor.getTemperature();
  sensor_data.waterHumidity = wthSensor.getHumidity();
  sensor_data.waterLevelSwitchFiring =  waterL.readValue() == 1 ? true : false;
  sensor_data.phLevel = ph.readValue(sensor_data.roomTemp);
  dc.reset(true);
}



void init_controllers(){
  extTempHmdSensor.init("Temp & Humidity Monitor", DHT11_PIN);
  delay(DHT_WAIT_TIME);
  ldr.init("ldr", LDR_PIN);
  const char* a = ldr.getSensorType();
  _debugWrite("LDR Type: ");
  _debugWrite(a);
  tdsSensor.init("TDS", TDS_PIN);
  wthSensor.init("WaterTempHumidity", -1);
  waterL.init("Water Level", WATER_PUMP_RELAY_PIN);  
  ph.init("PH Sensor", PH_PIN);
}
