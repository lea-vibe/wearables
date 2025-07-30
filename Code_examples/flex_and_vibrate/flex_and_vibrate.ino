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

created 2025
by Lea V. Pedersen 
*/

const int ledPin =  13; 
const int flexPin = A0; 
const int motorPin = 5;     // connected to mosfet, pwm pin 

int analogValue;  


void setup() {
  // put your setup code here, to run once:
   pinMode(ledPin, OUTPUT); //visual feedback
   pinMode(motorPin, OUTPUT);
   

}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(flexPin);                    //Read and save analog value from potentiometer
  analogValue = map(analogValue, 700, 1023, 0, 255);    //Map value 0-1023 to 0-255 (PWM). Vary this value depending 
  //on specific sensor and desired sensitivity. 
  delay(100);                                            


 if(analogValue > 15)             // replace number wth desired treshhold between 0-255
  {
    digitalWrite(ledPin, HIGH);   // turn the LED on
    analogWrite(motorPin, analogValue);  //turn motor on
    delay(300);                   //slight delay for feedback

  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn off the LED
    analogWrite(motorPin, 0);   //turn motor off
    delay(300);
  }

  
}
