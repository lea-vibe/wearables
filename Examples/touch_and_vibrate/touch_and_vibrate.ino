/*
Vibrate on touch

Turns the LilyPad Vibe Board on at max (255) when digitalRead() is 1 from wearbles touchsensor, acting as pushbutton. Also turns on 
onboard LED when motor is on for visual feedback.  

The circuit:
- Arduino Uno with chip removed
- LilyPad main HW-011
- LilyPad Vibe Board 
- Mosfet IRL2703
- Onboard LED

How to use Arduino Uno to code to lilyPad: https://www.instructables.com/How-to-upload-codes-to-Lilypad-Arduino-Without-FTD/ 
See a visual of circuit by following link in README.md file.

created 2025
by Lea V. Pedersen 
*/


const int motorPin = 5;     // connected to mosfet
const int ledPin =  13;     // LED pin
const int button1Pin = 10;  // pushbutton pin 


int button1State;  //check state of button press

void setup() {
  // put your setup code here, to run once:
   pinMode(ledPin, OUTPUT); //visual feedback
   pinMode(motorPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  button1State = digitalRead(button1Pin);
  pinMode(button1Pin, INPUT_PULLUP);//set internal pull up for button

  if (button1State == LOW)  // if we're pushing button 1
  {digitalWrite(ledPin, HIGH);  // turn the LED on
  analogWrite(motorPin, 255);  //turn motor on
  delay(300);                  //slight delay for feedback

  }
  else
  {
    digitalWrite(ledPin, LOW);  // turn off the LED
    analogWrite(motorPin, 0);   //turn motor off
    delay(300);
  }


  
}
