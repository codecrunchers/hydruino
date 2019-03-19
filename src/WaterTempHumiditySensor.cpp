#include "WaterTempHumiditySensor.h"
#include "DFRobot_SHT20.h"


void WaterTempHumiditySensor::init(char *desc){
  strncpy(_desc, desc, 255);
  sht20.initSHT20();                                  
  delay(100);
  sht20.checkSHT20();
}

dual_sensor_reading_t WaterTempHumiditySensor::readValue(){
  return dual_sensor_reading_t {0L, 0L};
}

float WaterTempHumiditySensor::getHumidity(){
  float humd = sht20.readHumidity();                  
  return humd;
}

float WaterTempHumiditySensor::getTemperature(){
  float temp = sht20.readTemperature();
  return temp;

}



