/*
  PWM
  Example using PWM with analogWrite(pin, value) to dim an LED.
  Use values of 0-255 to write duty cycles between fully off and fully on states. 
  Create LED circuit with LED connected to digital PWM pin 11.

  09-26-2023
  Jay J Gurung
  mtec1005
*/


const int LED = 11; // creates variable called LED and assigns value of 11
int ABC = 0; 
// setup function runs once at start up
void setup() {
  pinMode(LED, OUTPUT); 
}

// loop function runs infinitely
void loop() {
  /* Class Code
  analogWrite(LED, 255);   // writes duty cycle at 100%, LED fully on
  delay(1000);               // delays 1000 milliseconds (1 second)
  analogWrite(LED, 188);    // writes duty cycle at 75%, 
  delay(1000);               // delays 1000 milliseconds (1 second)
  analogWrite(LED, 127);    // writes duty cycle at 50%, LED dimmed at half
  delay(1000);               // delays 1 second
  analogWrite(LED, 64);    // writes duty cycle at 25%
  delay(1000);               // delays 1 second
  analogWrite(LED, 0);    // writes duty cycle at 0%, LED fully off
  delay(2000); 
  */
  
//my code to gradually increase the intensity
  analogWrite(LED, ABC);
  delay(5);
  if (ABC == 255){
    ABC = 0;
  }
  ABC = ABC +1;              // delays 2 seconds
}


// Modify the values of analogWrite() and delay() functions. Re-upload code to your board.

/*
Coding practice

const int LED = 11; 
int ABC = 0; 
void setup() {
  pinMode(LED, OUTPUT); 
}

void loop() {
  analogWrite(LED, ABC);
  delay(5);
  if (ABC == 255){
    ABC = 0;
  }
  ABC = ABC +1;              // delays 2 seconds
}
  
*/