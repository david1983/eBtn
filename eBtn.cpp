#include "Arduino.h"
#include "eBtn.h"
#include "asyncDelay.h"

typedef void (*callBack) ();



eBtn::eBtn(int pin){  
  _pin=pin;
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin,HIGH);
  _status = digitalRead(pin);
  _pressThrsld = 20;
};

void eBtn::handle(){
    _prevStatus = _status;
    _status = digitalRead(_pin);       
    if(_prevStatus==_status &&  _status==0)_event="hold";
    if(_prevStatus==_status &&  _status==1)_event="";
    if(_prevStatus!=_status &&  _status==0)_event="press";
    if(_prevStatus!=_status &&  _status==1 && _pressTime<_pressThrsld)_event="release";
    if(_prevStatus!=_status &&  _status==1 && _pressTime>=_pressThrsld)_event="long";
  
  if(_event=="release" || _event == "") _pressTime=0;
  else _pressTime++;
}

asyncDelay a = asyncDelay(100);
 void eBtn::on(String eventName, callBack cb){  
  if(_event==eventName) a.runJob(cb); 
 }


