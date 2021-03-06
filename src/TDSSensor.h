#ifndef TDSSENSOR_h
#define TDSSENSOR_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

namespace {
  const float VREF = 5.0 ;     // analog reference voltage(Volt) of the ADC
  const int8_t SCOUNT = 30 ;           // sum of sample point
}

#include "Sensor.h"

class TDSSensor : public Sensor {
  public:
    TDSSensor(sensor_type t) : Sensor(t){}
    float readValue() override; //TODO AutoCall on Timer
    /**
     * Get a sample over time
     */
    float getSampledValue();
  private:
    int analogBuffer[SCOUNT];    // store the analog value in the array, read from ADC
    int analogBufferTemp[SCOUNT];
    int analogBufferIndex = 0,copyIndex = 0;
    float averageVoltage = 0,tdsValue = 0,temperature = 25;
    int getMedianNum(int bArray[], int iFilterLen);

};

#endif

