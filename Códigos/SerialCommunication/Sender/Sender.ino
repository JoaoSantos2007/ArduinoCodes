//char mystr[5] = "Hello";
//char send_msg = "Mensagem do Arduino NANO";
//int msg;
String a = "A";
String b = "B";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //  Serial.write(mystr,5);

//  if (Serial.available()) {
//    msg = Serial.read();
//    Serial.println(msg);
//    delay(1000);
//  }
  Serial.print(a);
  delay(2000); 
  Serial.print(b);
  delay(2000);
}
