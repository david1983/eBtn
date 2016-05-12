#include "Arduino.h"
#include "eBtn.h"
#include <asyncDelay.h>

typedef void (*callBack) ();

// Initialize the button on the specified pin
eBtn::eBtn(int pin){  
  _pin=pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin,HIGH);
  _status = digitalRead(pin);  
  _pressThrsld = 2000;
  delay(100);
};

//check the status of the button, this function must be called inside a loop() or inside an interrupt
void eBtn::handle(){  
  _prevStatus = _status;
  _status = digitalRead(_pin);       
  if(_prevStatus==_status &&  _status==1)_event="";
  else if(_prevStatus!=_status &&  _status==0)_event="press";
  else if(_prevStatus==_status &&  _status==0)_event="hold";
  else if(_prevStatus!=_status &&  _status==1 && _pressTime<_pressThrsld)_event="release";
  else if(_prevStatus!=_status &&  _status==1 && _pressTime>=_pressThrsld)_event="long";
  // if(_event!="")Serial.println(_event);
  if(_event=="release" || _event == "") _pressTime=0;
  else _pressTime++;  

  if(_event=="press")_press();
  if(_event=="hold")_hold();
  if(_event=="release")_release();
  if(_event=="long")_long();
}

//setting an async 

void eBtn::on(String eventName, callBack cb){  
  if(eventName=="press")_press = cb;
  if(eventName=="hold")_hold = cb;
  if(eventName=="release")_release = cb;
  if(eventName=="long")_long = cb;
  
}

void eBtn::setThreshold(int t){
  _pressThrsld = t;
}

