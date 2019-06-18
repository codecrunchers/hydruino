#ifndef TTHREAD_h
#define TTHREAD_h

#include <SoftTimer.h>

class TThread : Task {


  public:
    TThread(MotorController* sensor, long interval) : Task(interval, &(TThread::doWork)){
      _sensor = sensor;
    }

    void start(){
      SoftTimer.add(this);
    }

    void stop() {
      SoftTimer.remove(this);
    }

    MotorController* getSensor(){
      return _sensor;
    }

  private:
    MotorController* _sensor;
    static void doWork(Task* t){
      TThread* tt = (TThread*)t;
      MotorController* s = tt->getSensor();
      Serial.print(s->getDesc());
      Serial.println(" Running");
      s->start();
      delay(3000);
      s->stop();      
      Serial.print(s->getDesc());
      Serial.println(" Done");
      
    }

};

#endif
