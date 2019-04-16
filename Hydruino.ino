#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"
#include "src/TDSSensor.h"
#include "src/WaterTempHumiditySensor.h"
#include "src/DisplayController.h"
#include <SoftTimer.h>

namespace {
 const int8_t LED_DATA_IN_PIN   = 7;
 const int8_t LED_CLK_PIN       = 5;
 const int8_t LED_LOAD_CS_PIN   = 6; 
 const int8_t DEBUG             = 1;
 const int8_t HOW_BRIGHT        = 10;
}



DHTSensor extTempHmdSensor = DHTSensor(DIGITAL_SENSOR);
LDRSensor ldr = LDRSensor(ANALOG_SENSOR);
TDSSensor tdsSensor = TDSSensor(ANALOG_SENSOR);
WaterTempHumiditySensor wthSensor = WaterTempHumiditySensor(ANALOG_SENSOR);
Sensor waterL = Sensor(DIGITAL_SENSOR);                                      
DisplayController dc = DisplayController();

int loopCount = 0;

void _loop(Task *t);
Task mainLoop(500, _loop);


void setup() {
  Serial.begin(9600);
  dc.init(LED_DATA_IN_PIN, LED_CLK_PIN, LED_LOAD_CS_PIN, HOW_BRIGHT);
  dc.busy(true);
  SoftTimer.add(&mainLoop); 
}



void _loop(Task* t) {
  Serial.print("T:" );
  Serial.println(extTempHmdSensor.getTemperature());
  Serial.print("H:" );
  Serial.println(extTempHmdSensor.getHumidity());
  Serial.print("LDR: ");
  Serial.println(ldr.readValue());
  Serial.print("TDS: ");
  Serial.println(tdsSensor.readValue());
  Serial.print("Water Temp: ");
  Serial.println(wthSensor.getTemperature());
  Serial.print("Water Humidity: ");
  Serial.println(wthSensor.getHumidity());
  Serial.print("Water Lvel: ");
  Serial.println(waterL.readValue());
  dc.write("12345678");


  delay(1000);

/*  loopCount++;
  if(loopCount == 10){
    Serial.print("TDS Sampled: ");
    Serial.println(tdsSensor.getSampledValue());
    loopCount = 0;
  }
*/

  


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
