/*
Jay J Gurung
10-17-2023

Piezo has a set of tones encoded that plays it on a loop once circuit is activated
  program can be made better using interrumpt
Photosensor - activates the circuit when it reaches the threshhold which is more than 400 units
Knobsensor - chnages the value of the tempo/spped of the tonal pattern and led blinking, 
            as well as the intensity of the led light that blinks synconomously with each note

*/
const int piezo = 2; // piezo pin
int sensorReading; //to track FSR input
int pitch;  // to track pitch
const int sensor = A1;
int value = 0;
const int LED = 9;
   float c = 16.35*3;
   float cs = 17.32*3;
   float d = 18.35*3;
   float ds =19.45*3;
   float e =20.6*3;
   float f = 21.83*3;
   float fs =23.12*3;
   float g =24.5*3;
   float gs =25.96*3;
   float a =27.5*3;
   float as =29.14*3;
   float b= 30.87*3;
  float ctone[] = {c,c*2,c*3,c*4,c*5,c*6,c*7};
   float cstone[] = {cs,cs*2,cs*3,cs*4,cs*5,cs*6,cs*7};
    float dtone[] = {d,d*2,d*3,d*4,d*5,d*6,d*7};
     float dstone[] = {ds,ds*2,ds*3,ds*4,ds*5,ds*6,ds*7};
      float etone[] = {e,e*2,e*3,e*4,e*5,e*6,e*7};
       float ftone[] = {f,f*2,f*3,f*4,f*5,f*6,f*7};
        float fstone[] = {fs,fs*2,fs*3,fs*4,fs*5,fs*6,fs*7};
         float gtone[] = {g,g*2,g*3,g*4,g*5,g*6,g*7};
          float gstone[] = {gs,gs*2,gs*3,gs*4,gs*5,gs*6,gs*7};
           float atone[] = {a,a*2,a*3,a*4,a*5,a*6,a*7};
            float astone[] = {as,as*2,as*3,as*4,as*5,as*6,as*7};
             float btone[] = {b,b*2,b*3,b*4,b*5,b*6,b*7};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
    
}

void loop() {
  sensorReading =  analogRead(A0);//photo sensor
  Serial.println(sensorReading);
  value = analogRead(sensor); //potentiometer
  delay(10);
  value = value/4; // value in time wont exceed more than 0.25 sec and works well with led as well
  if (sensorReading >400){
    //C major Arppegio
   
    tone(piezo, ctone[3], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0);
    tone(piezo, etone[3], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0);
    tone(piezo, gtone[3], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0);
    tone(piezo, etone[3], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0);
    tone(piezo, ctone[5], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0); 
    tone(piezo, gtone[3], value); 
    delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0); 
    tone(piezo, etone[3], value); 
      delay(value); 
      analogWrite(LED, value);
      delay(value); 
      analogWrite(LED, 0);
  // put your main code here, to run repeatedly:
  }
  else{
    analogWrite(LED, 0);
  }
}
