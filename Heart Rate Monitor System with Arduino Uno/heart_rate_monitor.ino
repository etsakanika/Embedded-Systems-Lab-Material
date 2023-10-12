// Arduino Code Snipet


// Include the Library for Pulse Sensor "PulseSensorPlayground"
#include <PulseSensorPlayground.h>     


//Declaration of variables
const int PulseSensor = A0;       
const int redLed = 11;
const int blueLed = 10;
int threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore
int tempSensor = A1; 
float temperature;
float threshold_min = 34.0;
float threshold_max = 38.0;


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
  
    pinMode(bluePin, OUTPUT);
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
  
  
    //Temperature Measurement
    temperature = map(((analogRead(tempSensor) - 20) * 3.04), 
                0, 1023, -40, 125);
  
  
    if(threshold_max >= temperature >= threshold_min){
    
     digitalWrite(blueLed, HIGH);
     Serial.println("Normal Τemperature");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Normal");
     lcd.setCursor(4,1);
     lcd.print("Temperature");
     lcd.display();
     delay(1000);
  }
  else{
 
    Serial.println("Problem with Temperature detected!");
    digitalWrite(blueLed, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Problem!");
    lcd.setCursor(4,1);
    lcd.print(temperature);
    lcd.print("C");
    lcd.display();
    delay(1000);
 }
  
}


