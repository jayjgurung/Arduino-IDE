/*
  FADING WITH PWM
  Example using PWM with analogWrite(pin, value) to fade an LED.
  Uses values of 0-255 to write duty cycles between fully off and fully on states.
  Create LED circuit with LED connected to digital PWM pin 11.

  last edited by 
  Jay J Gurung
  9-26-2023
*/

const int LED = 11;
const int buttonPin = 2;

int LEDState = LOW;
int buttonState = LOW;
int lastButtonState = LOW;

// setup function runs once at start up
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
}


// loop function runs infinitely
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  delay(10);

  if (buttonState == HIGH && lastButtonState == LOW) {
      LEDState = !LEDState;
  } else {

  }

  lastButtonState = buttonState;

  if (LEDState ==1){

    for (int i = 0 ; i <= 255; i += 5) { // for loop fades LED value from 0 to 255, incrementing by 1
      analogWrite(LED, i); //writes value of i to pin
      delay(50);  // short delay so LED effect is visible
    }
  }else{
    for (int i = 255 ; i >= 0; i -= 5) { // for loop fades LED value from 255 to 0, de-incrementing by 1
      analogWrite(LED, i);
      delay(50);
    }
  }
}