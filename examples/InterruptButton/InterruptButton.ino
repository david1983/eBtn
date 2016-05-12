#include <eBtn.h>

float n;
// Initialization of an eBtn on pin 0;
eBtn btn = eBtn(0);

void setup() {
	Serial.begin(115200);	
	// Here events are defined
	btn.on("press",pressFunc);
	btn.on("hold",holdFunc);
	btn.on("release",releaseFunc);
	btn.on("long",longPressFunc);
	//setting the interrupt on btn pin to react on change state
	attachInterrupt(0, pin_ISR, CHANGE);	
}

//function to handle the interrupt event
void pin_ISR(){
	btn.handle();
}


//callbacks functions
void pressFunc(){
	n = millis();
	Serial.println("Btn pressed");
}

void releaseFunc(){	
	Serial.println("Btn released after " + String((millis()-n) /1000) + " seconds");
}

void longPressFunc(){
	Serial.println("Btn released after a long press of " + String((millis()-n) /1000) + " seconds");	
}

void holdFunc(){
	Serial.println("Btn hold for: " + String((millis()-n) /1000) + " seconds");
}




void loop() {
	//btn::handle() is the function that constantly check for the btn states.
	
	for(int i=0;i<100;i++){
		delay(500);
		Serial.println("This is inside a for loop");
	}
	
}