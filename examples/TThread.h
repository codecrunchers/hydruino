#ifndef TTHREAD_h
#define TTHREAD_h

#include <SoftTimer.h>

class TThread : Task {


  public:
    TThread() : Task(5000, &(TThread::doWork)){}

    void start(){
      SoftTimer.add(this);
    }

    void stop() {
      SoftTimer.remove(this);
    }

  private:
    static void doWork(Task* t){
      TThread* tt = (TThread*)t;
      Serial.println("--");
    }

};

#endif
