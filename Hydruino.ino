#include "Sensor.h"
#include "DHTSensor.h"

DHTSensor extTempHmdSensor = DHTSensor();

void setup() {
  Serial.begin(9600);
  init_controllers();  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println(extTempHmdSensor.readValue());
}



void init_controllers(){
  extTempHmdSensor.init("Temp & Humidity Monitor", CP_DHT11_PIN);
}
