#ifndef DISPLAYCONTROLLER_h
#define DISPLAYCONTROLLER_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#include "LedControl.h" // https://playground.arduino.cc/Main/LedControl
#include <SoftTimer.h>
//asdasdsadsadasdsad
namespace {
  const int16_t RUN_INTERVAL  = 1000;
  const int8_t MAX_MSG  = 9;
}



class DisplayController : Task {

  public:
    DisplayController() : Task(RUN_INTERVAL, &(DisplayController::update)){}
    ~DisplayController();

    void init(int, int, int, int brightness);
    void reset(bool reset){ _reset = reset; }
    void alert(bool alert){
      _alert = true;
    }
    void busy(bool busy){
      _busy =  busy;
    }


    /**
     * Write a msg to display
     * will put display in alert mode if more than 8 chars long
     */
    void write(const char* msg){
      if(nullptr == msg){
        _alert = true;
        return;
      }

      size_t msglen = strlen(msg);

      if(msglen >= MAX_MSG){
        _alert = true;
        return;
      }

      _msg = new char[msglen];
      strcpy(_msg, msg);
      _msg = strrev(_msg);
    };


  private:
    static void update(Task *t);
    LedControl *_display;
    void do_reset();
    void do_alert();
    void do_write();
    void do_busy();
    char* _msg = nullptr;
    bool _alert  = false;
    bool _busy = false;
    bool _reset = false;
};

#endif
