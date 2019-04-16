#ifndef WATERTEMPHUMIDITYSENSOR_h
#define WATERTEMPHUMIDITYSENSOR_h

#include "Sensor.h"
#include "DFRobot_SHT20.h"



class WaterTempHumiditySensor : public Sensor {
  public:
    WaterTempHumiditySensor(sensor_type t) : Sensor(t){}

    typedef struct {
      float  temperature;
      float humidity;
    } dual_sensor_reading;

    void init(const char *desc, int pin) override;
    /**
     * Default to Temperature
     */
    float readValue() override ;   
    float getTemperature();
    float getHumidity();

    char* status();

  private:
    DFRobot_SHT20    sht20;
    dual_sensor_reading _t; //unused
};

#endif

