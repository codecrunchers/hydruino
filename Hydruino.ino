#include "src/Sensor.h"
#include "src/WaterPump.h"
#include <SoftTimer.h>

void _main(Task *t);
void TaskMotorController(Task *t);

Task mainLoop(MAIN_LOOP_INTERVAL, _main);
Task motorControllerLoop(5000, TaskMotorController);

Sensor waterLevel = Sensor(DIGITAL_SENSOR);
WaterPump motor = WaterPump(DIGITAL_SENSOR);

void setup()
{
  Serial.begin(9600);
  _debugWrite("---------------------------------------Init------------------------------------------------");
  init_controllers();
  SoftTimer.add(&mainLoop);
  SoftTimer.add(&motorControllerLoop);
}

void _main(Task *t)
{
  Serial.println("In Pseudo Main Loop");
}

void TaskMotorController(Task *t)
{
  _debugWrite("In MC Task");
  int full = (int)waterLevel.readValue();
  motor.start();
  while (full != RESEVOIR_FULL)
  {
    full = (int)waterLevel.readValue();
    _debugWrite("About to sleep for Motor");
    delay(2000);

  }
  motor.stop();
}

void init_controllers()
{
  motor.init("Pump", WATER_PUMP_RELAY_PIN);
  waterLevel.init("WaterLevel Meter 1 on Pin 8", RESEVOIR_TILT_SWITCH_PIN);
}
