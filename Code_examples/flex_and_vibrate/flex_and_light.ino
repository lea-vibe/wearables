/*
Light when flexed



The circuit:
- Arduino Uno with chip removed
- LilyPad main HW-011


How to use Arduino Uno to code to lilyPad: https://www.instructables.com/How-to-upload-codes-to-Lilypad-Arduino-Without-FTD/ 
See a visual of circuit by following link in README.md file.

created 2025
by Lea V. Pedersen 
*/

const int ledPin =  13;     // LED pin
const int flexPin = A0;  // p

const int motorPin = 5;     // connected to mosfet

int analogValue;  
int lastValue; 

void setup() {
  // put your setup code here, to run once:
   pinMode(ledPin, OUTPUT); //visual feedback
   pinMode(motorPin, OUTPUT);
   

}

void loop() {
  // put your main code here, to run repeatedly:



  analogValue = analogRead(flexPin);         //Read and save analog value from potentiometer
  analogValue = map(analogValue, 700, 900, 0, 255);      //Map value 0-1023 to 0-255 (PWM)
  analogWrite(ledPin, analogValue);                //Send PWM value to led
  delay(100);                                       //Small delay

 

 // if (analogValue <= 10 || lastValue <= analogValue -10)  // if we're pushing button 1
 if(analogValue >= 85)
  {
    digitalWrite(ledPin, HIGH);  // turn the LED on
    analogWrite(motorPin, analogValue);  //turn motor on
    delay(300);                  //slight delay for feedback

  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn off the LED
    analogWrite(motorPin, 0);   //turn motor off
    delay(300);
  }

  lastValue = analogValue; 
  
}
