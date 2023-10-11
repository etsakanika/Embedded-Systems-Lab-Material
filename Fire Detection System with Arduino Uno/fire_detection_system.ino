// Arduino Code Snipet
//

//Declaration of variables

#define buzzer 11
#define tempSensor A0

int fireSensor = 8;
int redLed = 10;
double tempSignal;
double fireSignal;
float temperature;
float threshold_min = 25.0;
float threshold_max = 38.0;



void setup()
{
  Serial.begin(9600);
  
  pinMode(fireSensor, INPUT);
  pinMode(tempSensor, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
}



void loop()
{
  
  temperature = map(((analogRead(tempSensor) - 20) * 3.04), 
                0, 1023, -40, 125);
  
  Serial.println(temperature);
  Serial.print(" \xC2\xB0"); // Shows degree symbol
  
  fireSignal = digitalRead(fireSensor);
  
  if(fireSignal == HIGH){
     digitalWrite(redLed, HIGH);
     delay(1000);
     digitalWrite(buzzer, HIGH);
     delay(1000);
  }else{
     digitalWrite(redLed, LOW);
     delay(1000);
     digitalWrite(buzzer, LOW);
     delay(1000);
  }
  
}
