#ifndef eBtn_h
#define eBtn_h

typedef void (*callBack) ();

class eBtn{
public:
  eBtn(int pin);
  void handle();
  void setThreshold(int t);
  void on(String eventName, callBack cb);
private:
  int _pin,_status,_prevStatus;
  int _pressThrsld,_pressTime,_startPress;  
  bool _readed;
  String _event;
  callBack _press, _release, _hold, _long;
};

#endif
