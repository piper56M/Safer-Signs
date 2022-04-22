#include "dht.h"
#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
int Relay1 = 3;
int Relay2 = 2;
int tempcutoff = 25;
int lightcutoff = 500;
int redpin = 11; // select the pin for the red LED
int bluepin =10; // select the pin for the  blue LED
int greenpin =9; // select the pin for the green LED
int val = 0;
const int PIN_TO_SENSOR = 4;   // the pin that OUTPUT pin of sensor is connected to
int pinStateCurrent   = LOW; // current state of pin
int pinStatePrevious  = LOW; // previous state of pin


void setup(){
 
  Serial.begin(9600);
 
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
   pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay1, OUTPUT);     //Set Pin3 as output
   pinMode(12, OUTPUT);         //Set Pin13 as output
  digitalWrite(12, HIGH);     //Set Pin13 High
  pinMode(Relay2, OUTPUT);     //Set Pin3 as output
    pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(PIN_TO_SENSOR, INPUT); // set arduino pin to input mode to read value from OUTPUT pin of sensor

}

void loop() {
  // Displays the working light and changes the colors
for(val = 255; val > 0; val--)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    Serial.println(val, DEC);
    delay(5); 
  }
  for(val = 0; val < 255; val++)
  {
    analogWrite(11, val);
    analogWrite(10, 255 - val);
    analogWrite(9, 128 - val);
    
    Serial.println(val, DEC);
    delay(5); 
  }
unsigned int AnalogValue;

AnalogValue = analogRead(A1);
DHT.read11(dht_apin);

  if (DHT.temperature>= tempcutoff){
    digitalWrite(Relay1, HIGH);
  }else{
    digitalWrite(Relay1, LOW);
  }
 if (AnalogValue>= lightcutoff){
    digitalWrite(Relay2, HIGH);
  }else{
    digitalWrite(Relay2, LOW);
  }
  Serial.print("temperature = ");
  //Serial.print(DHT.temperature); 
  Serial.println("C  ");
  Serial.print("Light = ");
  //Serial.println(AnalogValue);


  
  pinStatePrevious = pinStateCurrent; // store old state
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);   // read new state

  if (pinStatePrevious == LOW && pinStateCurrent == HIGH) {   // pin state change: LOW -> HIGH
   
      Serial.println("Motion detected!"); 
       digitalWrite(Relay2, HIGH);
   delay(5000);
 
  }
  else
  if (pinStatePrevious == HIGH && pinStateCurrent == LOW) {   // pin state change: HIGH -> LOW
  
        Serial.println("Motion stopped!");
        digitalWrite(Relay2, LOW);
    
  }



}
