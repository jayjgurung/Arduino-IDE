/*
6 led, 3 of which controlled by PhotoCell and rest of the three controlled by Potentiometer.
blue lights have a repetitive pattern and potentiometer increases and decreases the light intensity
greenlights have the same repetitice patten and photocell incereases and brightness when light threshold goes below a limit.

Coded and written by 
Jay J Gurung
10-3-2023

*/


const int photoSensor = A1;
const int knobSensor = A0;
const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 9;
const int LED5 = 10;
const int LED6 = 11;
int valueP= 0;
int valueK= 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);


z`}


void loop() {
  // put your main code here, to run repeatedly:
// POTENTIOMETER Controlled Light pttern
  valueP = analogRead(photoSensor);
  delay (10);  //Small delay
  valueP = valueP / 4; //Dividing value by 4 reduces range to max 255

  if (valueP >= 0 && valueP <= 200){
    analogWrite(LED4,255);
    delay(100);
    analogWrite(LED5,255);
    delay(100);
    analogWrite(LED6,255);
    delay(100);
    pot();
  }
  else if (valueP >= 201 && valueP <= 1023){
    analogWrite(LED4, 50);
    delay(50);
    analogWrite(LED4,0);
    analogWrite(LED5, 50);
    delay(50);
    analogWrite(LED5,0);
    analogWrite(LED6, 50);
    delay(50);
    analogWrite(LED6,0);
    pot();
  }
  Serial.println("Value P = " + valueP);
  Serial.println("Value K = " + valueK);
}

void pot(){

  // POTENTIOMETER Controlled Light pttern
  valueK = analogRead(knobSensor);
  delay(10);
  valueK = valueK/4;
  analogWrite(LED1, valueK);
  delay(100);
  analogWrite(LED2, valueK);
  delay(100);
  analogWrite(LED3, valueK);
  delay(100);
  analogWrite(LED1, 0);
  delay(100);
  analogWrite(LED2, 0);
  delay(100);
  analogWrite(LED3, 0);
  delay(100);

}