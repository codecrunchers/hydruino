#ifndef WATERTEMPHUMIDITYSENSOR_h
#define WATERTEMPHUMIDITYSENSOR_h

#include "Sensor.h"
#include "DFRobot_SHT20.h"


typedef struct dual_sensor_reading_t {
  float  temperature;
  float humidity;
} _dual_sensor_reading_t;


class WaterTempHumiditySensor {
  public:
    WaterTempHumiditySensor(){}

    void init(char *desc);
    /**
     * Default to Temperature
     */
    dual_sensor_reading_t readValue();
    float getTemperature();
    float getHumidity();

  private:
    char *_desc;
    DFRobot_SHT20    sht20;
};

#endif

