#include <SoftTimer.h>
#include "DisplayController.h"


namespace {
 const int8_t LED_DATA_IN_PIN   = 7;
 const int8_t LED_CLK_PIN       = 5;
 const int8_t LED_LOAD_CS_PIN   = 6; 
 const int8_t DEBUG             = 1;
 const int8_t HOW_BRIGHT        = 10;
}

DisplayController dc = DisplayController();

void _loop(Task *t);
Task mainLoop(500, _loop);


void setup() {
  Serial.begin(9600);
  dc.init(LED_DATA_IN_PIN, LED_CLK_PIN, LED_LOAD_CS_PIN, HOW_BRIGHT);
  dc.busy(true);
  SoftTimer.add(&mainLoop); 
}


void _loop(Task* t){
  Serial.println("Main Loop");
  dc.write("12345678");
}

