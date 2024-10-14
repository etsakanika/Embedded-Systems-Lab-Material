// Arduino Code Snipet


// Include the Library for Pulse Sensor "PulseSensorPlayground"
#include <PulseSensorPlayground.h>     


//Declaration of variables
const int PulseSensor = A0;       
const int redLed = 11;
const int greenLed = 10;
int threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore

// Creates an object
PulseSensorPlayground pulseSensor;  


void setup() {
  
	Serial.begin(9600);

	pulseSensor.analogInput(PulseSensor);   
	pulseSensor.blinkOnPulse(redLed);       // Blink on-board LED with heartbeat
	pulseSensor.setThreshold(threshold);   

  
	if (pulseSensor.begin()) {
		Serial.println("PulseSensor object created!");
	}
  
    pinMode(greenPin, OUTPUT);
}


void loop() {
  
    //Heart Rate Measurement
	int myBPM = pulseSensor.getBeatsPerMinute(); //BPM == Beats per Minute     

	if (pulseSensor.sawStartOfBeat()) {               
		Serial.println("♥  A HeartBeat Happened ! "); 
		Serial.print("BPM: ");
		Serial.println(myBPM);                        
		}

	delay(20);
    
}
