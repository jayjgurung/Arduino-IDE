/*
Jay J Gurung
9-19-2023

A Sketch to make the LEDs switch from blinking clockwise (at 1 blinks 0.25 second at 0.25 sec gap between each blink) 
to anti clock wise (at 1 blink per 0.15 second with 0.15 second gap between every blink)
*/


const int buttonPin = 2; // Creates variable called buttonPin, assigns to 2
const int LED1 =12; // creates var called LED1, assigns value of 13
const int LED2 =13;
const int LED3 =11; 
const int LED4 =10;
int buttonState = 0; // creates a variable to track buttonState, value of 0

void setup() {
  // put your setup code here, to run once:
  pinMode (LED1, OUTPUT); // initialize LED pin as outout
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);

  pinMode (buttonPin, INPUT); // initialize pushbutton PIn as input
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  delay(10);

  if (buttonState == HIGH) {
    digitalWrite (LED1, HIGH);
    delay(150);
    digitalWrite (LED1, LOW);
    delay(150);
    digitalWrite (LED2, HIGH);
    delay(150);
    digitalWrite (LED2, LOW);
    delay(150);
    digitalWrite (LED3, HIGH);
    delay(150);
    digitalWrite (LED3, LOW);
    delay(150);
    digitalWrite (LED4, HIGH);
    delay(150);
    digitalWrite (LED4, LOW);
    delay(150);
    
  }else{
    digitalWrite (LED4, HIGH);
    delay(250);
    digitalWrite (LED4, LOW);
    delay(250);
    digitalWrite (LED3, HIGH);
    delay(250);
    digitalWrite (LED3, LOW);
    delay(250);
    digitalWrite (LED2, HIGH);
    delay(250);
    digitalWrite (LED2, LOW);
    delay(250);
    digitalWrite (LED1, HIGH);
    delay(250);
    digitalWrite (LED1, LOW);
    delay(250);
  }
}
