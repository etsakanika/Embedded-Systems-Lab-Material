// Arduino Code Snipet
//

//Declaration of variables

#define buzzer 11

int fireSensor = 8;
double fireSignal;


void setup()
{
  Serial.begin(9600);
  
  pinMode(fireSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  
}


void loop()
{

  fireSignal = digitalRead(fireSensor);
  
  if(fireSignal == HIGH){
     digitalWrite(buzzer, HIGH);
     delay(1000);
  }else{
     digitalWrite(buzzer, LOW);
     delay(1000);
  }
  
}
