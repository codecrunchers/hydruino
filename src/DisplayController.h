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
#define RUN_INTERVAL 1000
#define MAX_MSG 8



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
      if(NULL == msg){
        _alert = true;
        return;
      }
      
      size_t msglen = strlen(msg);
      
      if(msglen >= 8){
        _alert = true;
      }

      _msg = new char[msglen];
      strcpy(_msg, msg);
      _write = true;
    };


  private:
    static void update(Task *t);
    LedControl *_display;
    void do_reset();
    void do_alert();
    void do_write();
    void do_busy();
    char *_msg;
    bool _alert  = false;
    bool _busy = false;
    bool _write =false;
    bool _reset = false;
};

#endif
