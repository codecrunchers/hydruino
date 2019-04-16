#include <SoftTimer.h>
#include "DisplayController.h"  
#include "LedControl.h"

#define MAX_LEN_MSG 8
#define DEBUG 1
#define DEFAULT_BRIGHT 8
#define LED_COUNT 1
#define DEFAULT_DEVICE 0
#define DELAY_TIME 250

void _debugWrite(const char* msg){
#ifdef DEBUG
  Serial.println(msg);
#endif
}


DisplayController::~DisplayController(){
  if(_msg){
    delete  [] _msg;
  }
  _display = NULL;
}


static void DisplayController::update(Task* t){
  DisplayController* _dc = (DisplayController*) t;
  _debugWrite("Running Led Thread");
  if(_dc->_busy == true){
    _dc->do_busy();
  }
}


void DisplayController::init(int LED_DATA_IN_PIN, int LED_CLK_PIN, int LED_LOAD_CS_PIN, int brightness){
  LedControl display = LedControl(LED_DATA_IN_PIN, LED_CLK_PIN ,LED_LOAD_CS_PIN, 1);
  display.shutdown(DEFAULT_DEVICE,false);
  if(brightness <= 15 && brightness > 0){
    display.setIntensity(DEFAULT_DEVICE, brightness);
  }else{
    display.setIntensity(DEFAULT_DEVICE, DEFAULT_BRIGHT);
  }
  _display = &display;
  SoftTimer.add(this);
  _debugWrite("Up");
}


void DisplayController::do_reset(){
  _display->clearDisplay(0);
}


void DisplayController::do_alert(){
  for(int cycle = 0; cycle < 8; cycle++){
    _display->setRow(DEFAULT_DEVICE,cycle,0x01);
  }
  do_reset(); 
}

#define BOTTOM_ROW 1
#define TOP_ROW 4
void DisplayController::do_busy(){
  int curRow = 0;
      delay(100);
      _display->setLed(DEFAULT_DEVICE, 
          curRow,
          3,
          true);

      delay(50);

      _display->setLed(DEFAULT_DEVICE, 
          curRow,
          2,
          true);



  for(int perimWalk = 0; perimWalk <= 20; perimWalk++){
    _display->setLed(DEFAULT_DEVICE, 
        perimWalk<=8 ? curRow++ : curRow--, 
        perimWalk<=8 ? BOTTOM_ROW : TOP_ROW ,  
        true);

    delay(50);

    if(perimWalk == 8){
      _display->setLed(DEFAULT_DEVICE, 
          7,
          6,
          true);

      delay(50);

      _display->setLed(DEFAULT_DEVICE, 
          7,
          5,
          true);

    }


    delay(50);
  }
  do_reset();

}


void DisplayController::do_write(){
  size_t msglen = strlen(_msg);
  if(msglen > MAX_LEN_MSG + 1) {
    do_alert();
    return;
  }

  for(int cycle = 0; cycle < msglen; cycle++){
    _display->setChar(DEFAULT_DEVICE, cycle, _msg[cycle], false);
  }

}


