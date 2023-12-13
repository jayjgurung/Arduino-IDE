/*
 * Blink 4 LEDs
 * Connect LEDs to digital pins 10, 11, 12 and 13.
 Code Edited:
    Jay J Gurung
    9-12-2023
 */

const int LED1 = 13; // create a variable called LED1 and assign its value to 12
const int LED2 = 12; // create a variable called LED2 and assign its value to 13
const int LED3 = 11; // create a variable called LED3 and assign its value to 11
const int LED4 = 10; // create a variable called LED4 and assign its value to 10

// put your setup code here, to run once:
void setup() {
  pinMode(LED1, OUTPUT); // initialize pins as outputs
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(LED1, HIGH); // turn on LED1
  delay(250);              // wait 250 milliseconds (1/4 second)
  digitalWrite(LED1, LOW);  // turn off LED1
  delay(250);              // wait 0.25 second
  digitalWrite(LED2, HIGH); // turn on LED2
  delay(500);              // wait 0.5 seconds
  digitalWrite(LED2, LOW);  // turn off LED2
  delay(500);              // wait 0.5 seconds
  digitalWrite(LED3, HIGH); // turn on LED3
  delay(250);              // wait 250 milliseconds (0.25 second)
  digitalWrite(LED3, LOW);  // turn off LED3
  delay(250);              // wait 0.25 second
  digitalWrite(LED4, HIGH); // turn on LED4
  delay(500);              // wait 0.5 seconds
  digitalWrite(LED4, LOW);  // turn off LED4
  delay(500);              // wait 0.5 seconds
}

// Modify the delay values to create different timing. Re-upload code to your board.