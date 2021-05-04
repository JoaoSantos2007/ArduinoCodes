int led = 4;
long tempo = 5000;
int distancia = 80;
const int buzzer = 8;
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 11 
#define pino_echo 10

 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup(){
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  if(distancia>=cmMsec){
    digitalWrite(led, HIGH);
    tone(buzzer,1500);
    delay(tempo);
  }else{
    digitalWrite(led, LOW);
    noTone(buzzer);
  }
}

/*int led = 4;
int botao = 6;
int estado = 0;
String statu = "Desligado";
String acao = "";
int tempo = 1000;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  digitalWrite(botao, HIGH);
}

void loop() {
  estado = digitalRead(botao);
  if (estado == LOW){
    if(statu == "Desligado"){
      acao = "Ligar";
      statu = "Ligado";
      delay(tempo);
    }else{
      acao = "Desligar";
      statu = "Desligado";
      delay(tempo);
    }
  }
  if(acao == "Ligar"){
    digitalWrite(led, HIGH);
  }else if(acao == "Desligar"){
    digitalWrite(led, LOW);
  }
}*/
