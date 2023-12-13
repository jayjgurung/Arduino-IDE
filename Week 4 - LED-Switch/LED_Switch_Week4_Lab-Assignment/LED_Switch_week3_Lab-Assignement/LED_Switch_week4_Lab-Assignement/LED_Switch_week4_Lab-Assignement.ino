/*
Jay J Gurung
9-19-2023
*/


const int buttonPin = 2; // Creates variable called buttonPin, assigns to 2
const int LED1 =13; // creates var called LED1, assigns value of 13

int buttonState = 0; // creates a variable to track buttonState, value of 0

void setup() {
  // put your setup code here, to run once:
  pinMode (LED1, OUTPUT); // initialize LED pin as outout
  pinMode (buttonPin, INPUT); // initialize pushbutton PIn as input
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  delay(10);

  if (buttonState == HIGH) {
    digitalWrite (LED1, HIGH);
  }else{
    digitalWrite(LED1,LOW);
  }
}
