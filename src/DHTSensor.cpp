#include "dht.h"  //DHTLib
#include "DHTSensor.h"



char* DHTSensor::status(){ 
  int chk = DHT.read11(getPin());
  switch (chk)
  {
    case DHTLIB_OK:  
      return "OK";
    case DHTLIB_ERROR_CHECKSUM: 
      return "Checksum error";
    case DHTLIB_ERROR_TIMEOUT: 
      return "Time out error"; 
    case DHTLIB_ERROR_CONNECT:        
      return "DHTLIB_ERROR_CONNECT";
    case DHTLIB_ERROR_ACK_L:        
      return "DHTLIB_ERROR_ACK_L";  
    case DHTLIB_ERROR_ACK_H:    
      return "DHTLIB_ERROR_ACK_H";    
    default: 
      return "Error";
  }

}

void DHTSensor::init(char *desc, int pin) {
  setPin(pin);
  setDesc(desc);
}

float DHTSensor::readValue() {
  DHT.read11(getPin());

  _t = {
    DHT.temperature,
    DHT.humidity
  };

  return _t.temperature;
}

float DHTSensor::getTemperature(){
  return readValue();
}

float DHTSensor::getHumidity(){
  readValue();
  return _t.humidity;

}
