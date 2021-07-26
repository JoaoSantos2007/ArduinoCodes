//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>


//Define os pinos para o trigger e echo
#define pino_trigger 11
#define pino_echo 10

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Define os pinos para o Motor 1
#define motor1A 8
#define motor1B 12
#define motor1V 3

//Define os pinos para o Motor 2
#define motor2A 7
#define motor2B 13
#define motor2V 5


//Define o tempo do delay
#define temp 300


void setup() {
  // put your setup code here, to run once:
  init_motors();
  define_functions();
  Serial.begin(115200);


}



void loop() {
  // put your main code here, to run repeatedly:
  float distancia = read_ultrassonic();
  apply_rules(distancia);
//  int velo = 100;
  //  go_foward(velo);
  //  delay(10000);
  //  stop_car();
  //  delay(5000);
  //  go_back(velo);
  //  delay(10000);
}


//Declara os motores do carrinho
void init_motors() {
  //Inicia o motor 1
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor1V, OUTPUT);

  //Inicia o motor 2
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor2V, OUTPUT);
}

void define_functions() {
  void go_foward(int velo);
  void go_back(int velo);
  void stop_car(void);
  float read_ultrassonic(void);
  void apply_rules(int cm);
}

void apply_rules(int cm) {
  if (cm <= 10) {
    stop_car();
  } else if (cm <= 70) {
    go_foward(100);
  } else if(cm > 70){
    go_foward(120);
  }
}


//Faz a leitura dos sensores ultrassônicos
float read_ultrassonic() {
  //Lê as informacões do sensor
  float cm;
  long microsec = ultrasonic.timing();
  cm = ultrasonic.convert(microsec, Ultrasonic::CM);

  //Exibe as informacões no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cm);
//  delay(2000);
  return (cm);
}

//Faz o carrinho ir para frente
void go_foward(int velo) {
  //Motor 1
  analogWrite(motor1V, velo);
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);

  //Motor 2
  analogWrite(motor2V, velo);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

//Faz o carrinho ir para trás
void go_back(int velo) {
  //Motor 1
  analogWrite(motor1V, velo);
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);

  //Motor 2
  analogWrite(motor2V, velo);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

//Para o carrinho
void stop_car() {
  //Motor 1
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);

  //Motor 2
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}




//digitalWrite(motor1A, HIGH);
//digitalWrite(motor1B, LOW);
//for (velo = 60; velo <= 120; velo++) {
//  analogWrite(motor1V, velo);
//  Serial.println(velo);
//  delay(temp);
//}
//for (velo = 120; velo >= 60; velo--) {
//  analogWrite(motor1V, velo);
//  delay(temp);
//}
//
//digitalWrite(motor1A, LOW);
//digitalWrite(motor1B, LOW);
//delay(5000);
//
//digitalWrite(motor1A, LOW);
//digitalWrite(motor1B, HIGH);
//for (velo = 60; velo <= 120; velo++) {
//  analogWrite(motor1V, velo);
//  delay(temp);
//}
//for (velo = 120; velo >= 60; velo--) {
//  analogWrite(motor1V, velo);
//  delay(temp);
//}
//
//digitalWrite(motor1A, LOW);
//digitalWrite(motor1B, LOW);
//delay(5000);
