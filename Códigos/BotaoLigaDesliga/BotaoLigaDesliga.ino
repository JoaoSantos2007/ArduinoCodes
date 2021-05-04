int led = 4;
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
}
