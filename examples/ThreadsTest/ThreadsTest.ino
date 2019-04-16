#include <SoftTimer.h>
#include "TThread.h"

// -- Define method signature.
void callBack1(Task* me);
void callBack2(Task* me);

Task t1(2000, callBack1);
Task t2(4000, callBack2);
TThread tthread = TThread();

void setup() {
  Serial.begin(9600);
  SoftTimer.add(&t1);
  SoftTimer.add(&t2);
  tthread.start();
}

void callBack1(Task* me) {
  Serial.println("t1");
}
void callBack2(Task* me) {
  Serial.println("t2");
}
