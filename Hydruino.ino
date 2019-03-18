#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"
#include "src/TDSSensor.h"
#include "src/WaterTempHumiditySensor.h"


DHTSensor extTempHmdSensor = DHTSensor(DIGITAL_SENSOR);
LDRSensor ldr = LDRSensor(ANALOG_SENSOR);
TDSSensor tdsSensor = TDSSensor(ANALOG_SENSOR);
WaterTempHumiditySensor wthSensor = WaterTempHumiditySensor(ANALOG_SENSOR);
int loopCount = 0;

void setup() {
  Serial.begin(9600);
  init_controllers();  
}

void loop() {
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
  Serial.print("\r\nDHT11 Status: ");
  char  *a = extTempHmdSensor.status();
  Serial.println(a);
  ldr.init("ldr", LDR_PIN);
  a = ldr.getSensorType();
  Serial.print("\r\nLDR Type: ");
  Serial.println(a);
  tdsSensor.init("TDS", TDS_PIN);
  wthSensor.init("WaterTempHumidity", -1);
}
