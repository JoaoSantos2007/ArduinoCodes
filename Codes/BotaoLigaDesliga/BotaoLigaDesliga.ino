//int led = 4;
//int botao = 6;
//int estado = 0;
//String statu = "Desligado";
//String acao = "";
//int tempo = 1000;
//void setup() {
//  pinMode(led, OUTPUT);
//  pinMode(botao, INPUT);
//  digitalWrite(botao, HIGH);
//}
//
//void loop() {
//  estado = digitalRead(botao);
//  if (estado == LOW){
//    if(statu == "Desligado"){
//      acao = "Ligar";
//      statu = "Ligado";
//      delay(tempo);
//    }else{
//      acao = "Desligar";
//      statu = "Desligado";
//      delay(tempo);
//    }
//  }
//  if(acao == "Ligar"){
//    digitalWrite(led, HIGH);
//  }else if(acao == "Desligar"){
//    digitalWrite(led, LOW);
//  }
//}

#include "EmonLib.h" //INCLUSÃO DE BIBLIOTECA
 
#define CURRENT_CAL 18.40 //VALOR DE CALIBRAÇÃO (DEVE SER AJUSTADO EM PARALELO COM UM MULTÍMETRO MEDINDO A CORRENTE DA CARGA)
const int pinoSensor = A2; //PINO ANALÓGICO EM QUE O SENSOR ESTÁ CONECTADO
 
EnergyMonitor emon1; //CRIA UMA INSTÂNCIA
 
void setup(){  
  Serial.begin(9600); //INICIALIZA A SERIAL
  emon1.current(pinoSensor, CURRENT_CAL); //PASSA PARA A FUNÇÃO OS PARÂMETROS (PINO ANALÓGIO / VALOR DE CALIBRAÇÃO)
}
 
void loop(){
  emon1.calcVI(17, 100); //FUNÇÃO DE CÁLCULO (17 SEMICICLOS / TEMPO LIMITE PARA FAZER A MEDIÇÃO)
  double currentDraw = emon1.Irms; //VARIÁVEL RECEBE O VALOR DE CORRENTE RMS OBTIDO
 
    Serial.print("Corrente medida: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(currentDraw); //IMPRIME NA SERIAL O VALOR DE CORRENTE MEDIDA
    Serial.println("A"); //IMPRIME O TEXTO NA SERIAL
}
