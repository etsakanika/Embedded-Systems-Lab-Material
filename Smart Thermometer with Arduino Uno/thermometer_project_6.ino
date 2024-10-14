// Arduino Code Snipet


//Declaration of variables
int tempSensor = A0;
int redPin = 11;
int bluePin = 10;
float temperature;
float threshold_min = 34.0;
float threshold_max = 38.0;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(tempSensor, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
   
} 


void loop() {
  
  /*tempSignal= analogRead(tempSensor);
  voltage = tempSignal * (5000 / 1023.0); //Convert the reading values into voltage
  temperature = voltage / 10; // Convert the voltage into the temperature in degree Celsius
  Serial.print(temperature);
  Serial.print(" \xC2\xB0"); // Degree Symbol
  Serial.print("C "); */
  
  temperature = map(((analogRead(tempSensor) - 20) * 3.04), 
                0, 1023, -40, 125);
  
  if(temperature > threshold_max){
    
     digitalWrite(redPin, HIGH);
     digitalWrite(bluePin, LOW);
     Serial.println("Ηigh Τemperature");
     delay(1000);
  }
  else if(temperature < threshold_min){
    
     digitalWrite(redPin, LOW);
     digitalWrite(bluePin, HIGH);
     Serial.println("Low Τemperature");
     delay(1000);
  }
  else{
 
    Serial.println("Normal Τemperature");
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(1000);
 }
