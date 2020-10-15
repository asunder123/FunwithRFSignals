/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
*/


/*#include <Stepper.h> */


/*const int ppr = 200;//passos totals per fer una volta
Stepper stepper1(ppr, 12,13); */
const int pwm = 5;
int sensorPin = A0;
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;


// select the input pin for the potentiometer
int ledPin = 0;

int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int sensorValue3 = 0;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin,OUTPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(pwm,OUTPUT);
 
  
}

void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  sensorValue1=analogRead(sensorPin1);
  sensorValue2=analogRead(sensorPin2);
  sensorValue3=analogRead(sensorPin3);
  //Print sensor Pin
  // turn the ledPin on
  ledPin = 13;





  sensorValue = analogRead(sensorPin);
 
    if(sensorValue>15)
    {
    digitalWrite(ledPin, HIGH);
    Serial.println(sensorValue);
    /* stepper1.setSpeed(sensorValue); */
    digitalWrite(ledPin, LOW);
    }

     if(sensorValue1>200){
     digitalWrite(ledPin, HIGH);   
    Serial.println(sensorValue1);
    /*stepper1.setSpeed(200); */
       digitalWrite(ledPin, LOW);
     }

    if(sensorValue2>200){  
     digitalWrite(ledPin, HIGH);   
    Serial.println(sensorValue2);
    /*stepper1.setSpeed(sensorValue2); */
      digitalWrite(ledPin, LOW);
     } 

     
    if(sensorValue3>200){   
    digitalWrite(ledPin, HIGH);
    Serial.println(sensorValue3);
    /*stepper1.setSpeed(sensorValue3);
    stepper1.step(sensorValue3/10); */
      digitalWrite(ledPin, LOW);
    } 
   
      


}
