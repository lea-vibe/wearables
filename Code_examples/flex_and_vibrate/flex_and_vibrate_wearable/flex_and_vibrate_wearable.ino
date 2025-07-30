/*
Vibrates with different intensity (analogWrite 0-255) depending on input from flexsensor. The value from the flexsonsor is mapped from 0-1023
to 0-255. Also turns on onboard LED when motor is on for visual feedback.    


The circuit:
- Arduino Uno with chip removed
- LilyPad main HW-011
- LilyPad Vibe Board 
- Mosfet IRL2703
- Onboard LED
- flexsensor 


How to use Arduino Uno to code to lilyPad: https://www.instructables.com/How-to-upload-codes-to-Lilypad-Arduino-Without-FTD/ 
See a visual of circuit by following link in README.md file.


To use the correct resistance, see: https://www.instructables.com/Analog-Input/ 


created 2025
by Lea V. Pedersen 
*/


const int analogInPin = A0;  
const int analogOutPin = 5;

int flexValue = 0;        
int outputValue = 0;  
const int ledPin =  13; 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //visual feedback
  
}

void loop() {
  // put your main code here, to run repeatedly:
  flexValue = analogRead(analogInPin);
  outputValue = map(flexValue, 0, 1023, 0, 255); // map measured value from flexsensor to correct range 
  analogWrite(analogOutPin, outputValue);
}
