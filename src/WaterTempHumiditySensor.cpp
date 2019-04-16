#include "WaterTempHumiditySensor.h"
#include "DFRobot_SHT20.h"


void WaterTempHumiditySensor::init(const char *desc, int pin){
  setPin(pin);
  setDesc(desc);

  sht20.initSHT20();                                  
  delay(100);
  sht20.checkSHT20();
}
/**
 * Default to Temperature
 */
float WaterTempHumiditySensor::readValue(){
  return 0L;
}
float WaterTempHumiditySensor::getHumidity(){
  float humd = sht20.readHumidity();                  
  return humd;
}

float WaterTempHumiditySensor::getTemperature(){
  float temp = sht20.readTemperature();
  return temp;

}



