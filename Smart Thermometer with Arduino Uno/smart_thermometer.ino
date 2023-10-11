// Arduino Code Snipet


// Include the Library for LCD Crystal Monitor
#include <LiquidCrystal.h>
  

//Declaration of variables
int tempSensor = A0;
int redPin = 11;
int bluePin = 10;
float tempSignal;
float voltage;
float temperature;
float threshold_min = 34.0;
float threshold_max = 38.0;

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


void setup() {
  
  Serial.begin(9600);
  
  pinMode(tempSensor, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Specify the LCD's number of columns and rows
  lcd.begin(16, 2);
  lcd.clear(); // Clear the screen for writing
  lcd.setCursor(0,0);
  lcd.print("Smart");
  lcd.setCursor(3,1);
  lcd.print("Thermometer"); 
  lcd.display();
  delay(5000); // Keep the words on screen for five seconds
   
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
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Ηigh Temperature");
     lcd.setCursor(4,1);
     lcd.print(temperature);
     lcd.print("C");
     lcd.display();
     delay(1000);
  }
  else if(temperature < threshold_min){
    
     digitalWrite(redPin, LOW);
     digitalWrite(bluePin, HIGH);
     Serial.println("Low Τemperature");
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Low Temperature");
     lcd.setCursor(4,1);
     lcd.print(temperature);
     lcd.print("C");
     lcd.display();
     delay(1000);
  }
  else{
 
    Serial.println("Normal Τemperature");
    digitalWrite(redPin, LOW);
    digitalWrite(bluePin, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(4,1);
    lcd.print(temperature);
    lcd.print("C");
    lcd.display();
    delay(1000);
 }

  /*
 //Display measured temperature on 16x2 Crystal LCD
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Temperature");
 lcd.setCursor(4,1);
 lcd.print(temperature);
 lcd.print("C");
 lcd.display();
 delay(1000);
 */

}
