# eBtn
An Arduino library to create buttons and handle events using callbacks.
The library handle the following events:

- press
- release
- hold
- longPress

**Usage**
    
    eBtn btn = eBtn(btnPin);
    
    btn.on("press",callbackFn);
    
    void callbackFn(){
      //do something here
    }

