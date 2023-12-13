/*
10-31-2023
Jay J Gurung

HOW THE CIRCUT BEHAVES:

Photo Sensor determindes which MODE to be in

  Mode A [Dark / photosensor detected value is low]:
    * * features * * 
        piezo beeps a note every loop cycle
        potentiometer controls the speed of the blinking and angle of servo
        has 2 patterns 
              pattern 1 (angle > 90 ): LED blinks left to right
              pattern 2 (angle < 90 ): LED blinks right to left
      
  Mode B [Bright / photosensor detected value is high]:
    * * features * *
        potentiometer knob controls the tempo of the beep
        LEDs blink everytime a piezo beeps a note played
      
  */


#include <Servo.h> // include Arduino Servo library

const int servoPin = 9;  // create servoPin variable, assign 9
const int LED = 2;  // create LED variable, assign 2
const int LED2 = 4;  // create LED variable, assign 4
const int LED3 = 7;  // create LED variable, assign 4
const int potPin = A0; // Knob unit signal assigned to A0
const int photoSensor = A1; // Photo sensor assigner to A1
const int speaker = 12; // piezo assigned to 12

Servo servo;  // create Servo object

float reading = 0; //keeping track of the reading
float angle = 0;   // variable to track servo position in degrees
float photoRead;
float pitch;
float brightness;
float blinkSpeed;
float tempo;

void setup() {
  servo.attach(servoPin); //attach servo variable to control pin
  pinMode(LED,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED3,OUTPUT);
  Serial.begin(9600);
}


void loop() {
  photoRead = analogRead(A1);  // assigning values of PhotoSensor read to PhotoRead
  brightness = photoRead/4; // converting value received to 255 max

  reading = analogRead(A0); // assigning Knob reading to reading
  angle = reading/5.6; // converting the value so it limits to 360

  servo.write(angle); //motor rotates to the angle 

  Serial.println(brightness);
//LIMITER ON BLINK so it does not blink faster than 100ms and slower than 400ms
  if (reading<100){
    blinkSpeed =100;
  } else if(reading>400){
    blinkSpeed =400;
  } else {
    blinkSpeed = reading;
  }


  tempo = reading; //60000 ms is one minute thus, if you want 90bpm you divide a minute 90 times.


  if (brightness <215 && brightness > 0){
    tone(speaker, 400, tempo/2); 
    if (angle<90){
        digitalWrite(LED,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED,LOW);
        delay(blinkSpeed);
        digitalWrite(LED2,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED2,LOW);
        delay(blinkSpeed);
        digitalWrite(LED3,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED3,LOW);
        delay(blinkSpeed);
    } else{
        digitalWrite(LED3,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED3,LOW);
        delay(blinkSpeed);
        digitalWrite(LED2,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED2,LOW);
        delay(blinkSpeed);
        digitalWrite(LED,HIGH);
        delay(blinkSpeed);
        digitalWrite(LED,LOW);
        delay(blinkSpeed);

    }
  } else if (brightness>=100){
     tone(speaker, 400, tempo/2); 
      delay(tempo/4); 
      digitalWrite(LED, HIGH);
      delay(tempo/4); 
      digitalWrite(LED, LOW);
    tone(speaker, 800, tempo/2); 
      delay(tempo/4); 
      digitalWrite(LED2, HIGH);
      delay(tempo/4); 
      digitalWrite(LED2, LOW);
    tone(speaker, 1200, tempo/2); 
      delay(tempo/4); 
      digitalWrite(LED3, HIGH);
      delay(tempo/4); 
      digitalWrite(LED3, LOW);
  }
}