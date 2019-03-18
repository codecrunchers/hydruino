#ifndef DHTSENSOR_h
#define DHTSENSOR_h

#include "dht.h"  //DHTLib
#include "Sensor.h"




class DHTSensor : public Sensor{
  public:
    inline DHTSensor::DHTSensor(sensor_type t) : Sensor(t){}
    typedef struct {
      float  temperature;
      float humidity;
    } dht_sensor_reading;

    void init(char *desc, int pin) override;
    float readValue() override ;   //defaults to Temperature
    float getTemperature();
    float getHumidity();

    char* status();

  private:
    dht DHT;
    dht_sensor_reading _t;
};

#endif
