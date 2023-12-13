/*
Code by 
Jay J Gurung
9-26-2023

Sketch / code to change the LED pattern from switchingfast between one LED blink to another, to varying intensity low to high and viceversa.
*/

//initializing LED pins and Button pin
const int LED1 = 3;
const int LED2 = 6;
const int LED3 = 10;
const int LED4 = 11;
const int buttonPin = 2;

int LEDState = LOW;
int buttonState = LOW;
int lastButtonState = LOW;

void setup() {
  // setting up inputs and outputs
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
  pinMode (buttonState, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  delay(10);

  // Created a condition where LEDState would change if the current digitalRead is on and previously off.
  if (buttonState == HIGH && lastButtonState == LOW) {
      LEDState = !LEDState;
  } else {

  }

  lastButtonState = buttonState;
  

  if(LEDState == HIGH){
    for (int i = 0; i <=255; i+= 15){
      analogWrite(LED1, i);
      delay(5);
      analogWrite (LED2,i);
      delay(5);
      analogWrite(LED3, i);
      delay(5);
      analogWrite (LED4,i); 
      delay(5);
    }
    for (int i = 255; i >=0; i-= 10){
      analogWrite(LED1, i);
      delay(5);
      analogWrite (LED2,i);
      delay(5);
      analogWrite(LED3, i);
      delay(5);
      analogWrite (LED4,i); 
      delay(5);
    }
  }
  if(LEDState == LOW){
    digitalWrite(LED1, HIGH);
    delay(70);
    digitalWrite(LED1, LOW);
    digitalWrite (LED2,HIGH);
    delay(70);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    delay(70);
    digitalWrite(LED3, LOW);
    digitalWrite (LED4,HIGH);
    delay(70);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    delay(70);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(70);
    digitalWrite(LED2, LOW);
  }
}
