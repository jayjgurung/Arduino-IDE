const int LED1 = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode (LED1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i =0; i<255; i+=1){
  analogWrite(LED1, i);
  delay(2);
  }
  analogWrite(LED1,255);
  delay(300);
  analogWrite(LED1,120);
  delay(300);
  analogWrite(LED1, 70);
  delay(300);
  analogWrite(LED1, 0);
  delay(300);
}

