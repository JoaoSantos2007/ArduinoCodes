const int buzzer = 11;

void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() {
  tone(buzzer,1500);
  delay(500);

  noTone(buzzer);
  delay(500);
}
