/*
10-24-2023
Jay J Gurung

The potentiometer knob controls the angle
the angle controls the 3 LEDs' pattern direction and speed.
*/


#include <Servo.h> // include Arduino Servo library

const int servoPin = 9;  // create servoPin variable, assign 9
const int LED = 2;  // create LED variable, assign 2
const int LED2 = 4;  // create LED variable, assign 4
const int LED3 = 7;  // create LED variable, assign 4
const float potPin = A0;

Servo servo;  // create Servo object
float reading = 0; //keeping track of the reading
float angle = 0;   // variable to track servo position in degrees
float halfAng = 0;

//tone

void setup() {
  servo.attach(servoPin); //attach servo variable to control pin
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  reading = analogRead(potPin);
  angle = reading/5.6;
  
  servo.write(angle);
  Serial.println(angle);
  Serial.println(reading);
  if (angle<90){
      digitalWrite(LED,HIGH);
      delay(angle);
      digitalWrite(LED,LOW);
      delay(angle);
      digitalWrite(LED2,HIGH);
      delay(angle);
      digitalWrite(LED2,LOW);
      delay(angle);
      digitalWrite(LED3,HIGH);
      delay(angle);
      digitalWrite(LED3,LOW);
      delay(angle);
  } else{
      float halfAngle = angle-90;
      digitalWrite(LED3,HIGH);
      delay(halfAngle);
      digitalWrite(LED3,LOW);
      delay(halfAngle);
      digitalWrite(LED2,HIGH);
      delay(halfAngle);
      digitalWrite(LED2,LOW);
      delay(halfAngle);
      digitalWrite(LED,HIGH);
      delay(halfAngle);
      digitalWrite(LED,LOW);
      delay(halfAngle);

  }

         //led to react if the angle is less than 60 degrees
  // if (angle < 60){
  //     digitalWrite(LED,HIGH);
  //     delay(angle);
  //     digitalWrite(LED,LOW);
  //     delay(angle);
  // }


          // // scan from 0 to 180 degrees
  // for (angle = potPin; angle < 180; angle+=45) {
  //   // if (angle == 0){
  //   //   digitalWrite(LED,HIGH);
  //   //   delay(10);
  //   //   digitalWrite(LED,LOW);
  //   //   delay(10);
  //   // }
  //   servo.write(angle);
  //   delay(200);
  // }
         // // now scan back from 180 to 0 degrees
  // for (angle = 180; angle > 0; angle-=45) {
  //   // if (angle == 180){
  //   //   digitalWrite(LED,HIGH);
  //   //   delay(10);
  //   //   digitalWrite(LED,LOW);
  //   //   delay(10);
  //   // }
  //   servo.write(angle);
  //   delay(400);
  // }
}