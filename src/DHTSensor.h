#ifndef DHTSENSOR_h
#define DHTSENSOR_h

#include "DHT.h"
#include "Sensor.h"

#define DHTTYPE                 DHT11     

class DHTSensor : public Sensor {

  public:
    float readValue() override;  

  private:
//    DHT dht(CP_DHT11_PIN, DHTTYPE);
};

#endif
