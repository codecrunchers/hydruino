#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"
#include "src/TDSSensor.h"
#include "src/WaterTempHumiditySensor.h"
#include "src/DisplayController.h"
#include <SoftTimer.h>


DHTSensor extTempHmdSensor = DHTSensor(DIGITAL_SENSOR);
LDRSensor ldr = LDRSensor(ANALOG_SENSOR);
TDSSensor tdsSensor = TDSSensor(ANALOG_SENSOR);
WaterTempHumiditySensor wthSensor = WaterTempHumiditySensor(ANALOG_SENSOR);
Sensor waterL = Sensor(DIGITAL_SENSOR);                                      
DisplayController dc = DisplayController();

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

  dc.reset(true);
}



void init_controllers(){
  extTempHmdSensor.init("Temp & Humidity Monitor", DHT11_PIN);
  delay(1000); //DHT 11 avoid TO
  ldr.init("ldr", LDR_PIN);
  char a = ldr.getSensorType();
  Serial.print("\r\nLDR Type: ");
  Serial.println(a);
  tdsSensor.init("TDS", TDS_PIN);
  wthSensor.init("WaterTempHumidity", -1);
  waterL.init("", 2);  
}
