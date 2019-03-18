#include "src/Sensor.h"
#include "src/DHTSensor.h"
#include "src/LDRSensor.h"

DHTSensor extTempHmdSensor = DHTSensor(DIGITAL_SENSOR);
LDRSensor ldr = LDRSensor(ANALOG_SENSOR);

void setup() {
  Serial.begin(9600);
  init_controllers();  
}

void loop() {
  delay(3000);
  Serial.print("T:" );
  Serial.println(extTempHmdSensor.getTemperature());
  delay(1000);
  Serial.print("H:" );
  Serial.println(extTempHmdSensor.getHumidity());
  Serial.print("LDR: ");
  Serial.println(ldr.readValue());

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


}
