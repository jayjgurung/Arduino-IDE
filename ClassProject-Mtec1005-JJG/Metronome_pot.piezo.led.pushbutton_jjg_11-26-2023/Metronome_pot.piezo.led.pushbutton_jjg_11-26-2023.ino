

#include <Servo.h> // include Arduino Servo library

const int led_A = 3;
const int led_B = 5;
const int led_C = 6;
const int led_D = 9;

const int toneUpButton = 8;
const int toneDownButton = 7;

const int playPauseButton = 13;

int knobValue; 
float brightnessValue;
float beatDuration;
float bpm;

const int servoPin= 12;
int angle;
Servo servoArm;

int LED[] = {led_A, led_B, led_C, led_D};

int n = 0;
float notes[] = {523.25,554.37,587.33,622.25,659.25,698.46,739.99,783.99,830.61,880.00,932.33,987.77};
float toneA ;
float toneB ;
float TONE[4] ;

const int knobSensor = A0;
const int photoSensor = A1;

const int speaker = 2;

bool status ;
bool buttonState = false;

bool buttonUp;
bool buttonDown;
bool lastStatus = 0;

void playPause(bool status, bool lastStatus){
  for (int i=0; i<4; i++){
    // onOff();
    buttonUp = digitalRead(toneUpButton);
    delay(1);
    buttonDown = digitalRead(toneDownButton);
    delay(1);
  
    angle = map(n,0,11,180,0);
    servoArm.write(angle);
    Serial.println("angle :"+String(angle));

    if (buttonUp == HIGH and n!=11){
      n++;
    }

    if (buttonDown == HIGH and n!=0){
      n--;
    }
  
    toneA = notes[n];
    toneB = toneA / 2;
    float TONE[] = {toneA, toneB, toneB, toneB};

    knobValue = analogRead(knobSensor);
    bpm = map(knobValue,0,1023,200,60);
    beatDuration = 60000/bpm;



    tone(speaker, TONE[i],55);
    analogWrite(LED[i], 255);
    delay(beatDuration);
    analogWrite(LED[i], 0);

    // Serial.println(bpm);
    // Serial.println(toneA);
    }
  onOff();
}

void onOff(){
  if(digitalRead(playPauseButton) == 1){
        delay(1000);
        while(digitalRead(playPauseButton) == 0){
          
        }
        
        loop();
        // return ;
      }
      else if (digitalRead(playPauseButton) == 0) {
        playPause(status, lastStatus);
      }
}


void setup() {
  servoArm.attach(servoPin);
  Serial.begin(9600);

  pinMode(led_A, OUTPUT);
  pinMode(led_B, OUTPUT);
  pinMode(led_C, OUTPUT);
  pinMode(led_D, OUTPUT);

  pinMode(toneUpButton, INPUT);
  pinMode(toneDownButton, INPUT);
  pinMode(playPauseButton, INPUT);

}

void loop() {
  status = digitalRead(playPauseButton);
  delay(1);
 // Serial.println("status : "+ String(status));

  if ( status == 1){
    lastStatus = status;
    //Serial.println("Beep Beep");
    playPause(status, lastStatus);
     
  
  // if(status )
  }
}

