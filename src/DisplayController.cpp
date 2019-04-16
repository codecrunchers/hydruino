#include <SoftTimer.h>
#include "DisplayController.h"  
#include "LedControl.h"


namespace {
  const int8_t MAX_LEN_MSG  = 8;
  const int8_t DEFAULT_BRIGHT = 8;
  const int8_t LED_COUNT =  1;
  const int8_t DEFAULT_DEVICE = 0;
  const int8_t DELAY_TIME = 250;
  const int8_t DEBUG  = 1;
  const int8_t DELAY_LED = 50;

}

void _debugWrite(const char* msg){
#ifdef DEBUG
  Serial.println(msg);
#endif
}


DisplayController::~DisplayController(){
  if(_msg != nullptr){
    delete  [] _msg;
  }
  _display = NULL;
}


static void DisplayController::update(Task* t){
  DisplayController* _dc = (DisplayController*) t;
  _debugWrite("Running Led Thread");

  if(_dc->_busy == true){
    _dc->do_busy();
  }else if(_dc->_alert == true){
    _dc->do_alert();
  }else if (_dc->_reset == true){
    _dc->do_reset();
  }else if(nullptr != _dc->_msg){
    _dc->do_write();
  }
}


void DisplayController::init(int led_data_in_pin, int led_clk_pin, int led_load_cs_pin, int brightness){
  LedControl display = LedControl(led_data_in_pin, led_clk_pin ,led_load_cs_pin, 1);
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
  _reset = false;
  if(nullptr !=_msg){
    delete [] _msg;
  }
  _busy = false;
  _alert = false;
}


void DisplayController::do_alert(){
  for(int cycle = 0; cycle < MAX_LEN_MSG; cycle++){
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

  delay(DELAY_LED);

  _display->setLed(DEFAULT_DEVICE, 
      curRow,
      2,
      true);

  for(int perimWalk = 0; perimWalk <= 20; perimWalk++){
    _display->setLed(DEFAULT_DEVICE, 
        perimWalk<=8 ? curRow++ : curRow--, 
        perimWalk<=8 ? BOTTOM_ROW : TOP_ROW ,  
        true);

    delay(DELAY_LED);

    if(perimWalk == 8){
      _display->setLed(DEFAULT_DEVICE, 
          7,
          6,
          true);

      delay(DELAY_LED);

      _display->setLed(DEFAULT_DEVICE, 
          7,
          5,
          true);

    }


    delay(DELAY_LED);
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


