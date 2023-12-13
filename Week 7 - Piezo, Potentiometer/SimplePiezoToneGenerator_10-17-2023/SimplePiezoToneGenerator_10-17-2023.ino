const int piezo = 2;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(piezo,523,300);
  delay(200);
  tone(piezo,622,300);
  delay(200);
  tone(piezo,698,300);
  delay(200);  
  tone(piezo,739,300);
  delay(200);
  tone(piezo,783,300);
  delay(200);
  tone(piezo,415,300);
  delay(200);  
  tone(piezo,466,300);
  delay(200);
  tone(piezo,493,150);
  delay(50);
  tone(piezo,987,150);
  delay(50);
  tone(piezo,493,150);
  delay(50);
  tone(piezo,987,150);
  delay(50);
}
