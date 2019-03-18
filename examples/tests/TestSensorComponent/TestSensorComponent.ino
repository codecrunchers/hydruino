#line 2 "TestSensorComponent.ino"

#include <AUnitVerbose.h>
#include "Sensor.h"

using namespace aunit;

Sensor s;

// in setup, we prepare the serial port.
void setup() {
    Serial.begin(115200);
    while(!Serial);
}

// we just call the test runner in loop
void loop() {
    TestRunner::run();
}

test(addingTwoNumbersTogether) {
    assertEqual(s.init("",1), 20);
}


