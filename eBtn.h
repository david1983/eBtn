#ifndef eBtn_h
#define eBtn_h

typedef void (*callBack) ();

class eBtn{
public:
  eBtn(int pin);
  void handle();
  void on(String eventName, callBack cb);
private:
  int _pin,_status,_prevStatus;
  int _pressThrsld,_pressTime;  
  String _event;
};

#endif
