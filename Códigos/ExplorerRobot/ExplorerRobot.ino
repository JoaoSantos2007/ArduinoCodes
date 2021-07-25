
//Motor 1
#define motor1A 8
#define motor1B 12
#define motor1V 3

//Motor 2
#define motor2A
#define motor2B
#define motor2V

#define temp 300

int velo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1V, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  for (velo = 60; velo <= 120; velo++) {
    analogWrite(motor1V, velo);
    Serial.println(velo);
    delay(temp);
  }
  for (velo = 120; velo >= 60; velo--) {
    analogWrite(motor1V, velo);
    delay(temp);
  }

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  delay(5000);

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  for (velo = 60; velo <= 120; velo++) {
    analogWrite(motor1V, velo);
    delay(temp);
  }
  for (velo = 120; velo >= 60; velo--) {
    analogWrite(motor1V, velo);
    delay(temp);
  }

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  delay(5000);
}
