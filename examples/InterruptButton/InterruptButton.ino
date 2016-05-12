/*
	InterruptButton

	Simple sketch to control a button on pin 0 using
	the eBtn library and Interrupt

	The circuit:
	pushButton attached on pin 0

	Created 11 May 2016
	By Davide Andreazzini
	
	https://github.com/david1983/eBtn

*/
#include <eBtn.h>

float n;
// Initialization of an eBtn on pin 0;
const int btnPin = 0;
eBtn btn = eBtn(btnPin);

void setup() {
	Serial.begin(115200);	
	// Here events are defined
	btn.on("press",pressFunc);
	btn.on("hold",holdFunc);
	btn.on("release",releaseFunc);
	btn.on("long",longPressFunc);
	//setting the interrupt on btn pin to react on change state
	attachInterrupt(btnPin, pin_ISR, CHANGE);	
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