#ifndef DHTSENSOR_h
#define DHTSENSOR_h

#include "dht.h"  //DHTLib
#include "Sensor.h"




class DHTSensor : public Sensor {
  public:
    DHTSensor(sensor_type t) : Sensor(t){}
    typedef struct {
      float  temperature;
      float humidity;
    } dht_sensor_reading;

    void init(const char *desc, int8_t pin) override;
    float readValue() override ;   //defaults to Temperature
    float getTemperature();
    float getHumidity();

    const char* status();

  private:
    dht DHT;
    dht_sensor_reading _t;
};

#endif
