#include "TDSSensor.h"


float TDSSensor::getSampledValue(){
  for(int copyIndex=0;copyIndex<SCOUNT;copyIndex++)
    analogBufferTemp[copyIndex]= analogBuffer[copyIndex];

  averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 1024.0; // read the analog value more stable by the median filtering algorithm, and convert to voltage value
  float compensationCoefficient=1.0+0.02*(temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
  float compensationVolatge=averageVoltage/compensationCoefficient;  //temperature compensation
  tdsValue=(133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5; //convert voltage value to tds value  
#ifdef DEBUG
  Serial.print("TDS Value: ");
  Serial.print(tdsValue, 0);
  Serial.println("ppm\r\n");
#endif
  return tdsValue;
}

/**
 * Get a TDS Sample, Store to Buffer -
 * @return -1L if buffer not full, else  a TDS value
 */
float TDSSensor::readValue(){
  float sensorVal = Sensor::readValue();
  analogBuffer[analogBufferIndex] = sensorVal;    //read the analog value and store into the buffer
  analogBufferIndex++;
  if(analogBufferIndex == SCOUNT) {
    analogBufferIndex = 0;
    return getSampledValue();
  }
  else  {
    return  -1L;
  }
}

//FROM DFRObot
int TDSSensor::getMedianNum(int bArray[], int iFilterLen) 
{
  int bTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
    bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++) 
  {
    for (i = 0; i < iFilterLen - j - 1; i++) 
    {
      if (bTab[i] > bTab[i + 1]) 
      {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];
  else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  return bTemp;
}

