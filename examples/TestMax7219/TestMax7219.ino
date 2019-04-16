#include <SoftTimer.h>
#include "DisplayController.h"


#define LED_DATA_IN_PIN   7
#define LED_CLK_PIN       5
#define LED_LOAD_CS_PIN   6 
#define DEBUG 1
#define HOW_BRIGHT 10

DisplayController dc = DisplayController();

void _loop(Task *t);
Task mainLoop(800, _loop);


void setup() {
  Serial.begin(9600);
  dc.init(LED_DATA_IN_PIN, LED_CLK_PIN, LED_LOAD_CS_PIN, HOW_BRIGHT);
  dc.busy = true;
  SoftTimer.add(&mainLoop); 
}


void _loop(Task* t){
  Serial.println("Main Loop");
}

