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



class DisplayController : Task {

  public:
    DisplayController() : Task(1000, &(DisplayController::update)){}

    void init(int,int,int, int brightness);
    bool reset  = false;
    bool busy = false;


  private:
    LedControl *_display;
    void do_reset();
    void do_alert();
    void do_write(const char* msg, int len, bool flash);
    void do_busy();
    static void update(Task *t);
};

#endif
