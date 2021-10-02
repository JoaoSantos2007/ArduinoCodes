int led = 4;
int botao = 6;
int interruptor = 3;
int estado_inte = 0;
int estado_led = 0;
int estado_botao;
int estado_inte_ant;
int estado_inte_at;
unsigned long lastDebounceTime = 0; // última vez que o botão foi pressionado
unsigned long debounceDelay = 70;   // O intervalo, igual ao delay do código anterior

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(interruptor, INPUT);
  Serial.begin(115200);
  estado_inte_at = digitalRead(interruptor);
  if (estado_inte_at == 0) {
    estado_inte_ant = 1;
  } else if (estado_inte_at == 1) {
    estado_inte_ant = 0;
  }
  estado_botao = digitalRead(botao);
}

void alterar() {
  if (estado_led == HIGH) {
    estado_led = LOW;
  } else if (estado_led == LOW) {
    estado_led = HIGH;
  }
}

void loop() {
  //Simular Interruptor
  estado_inte_at = digitalRead(interruptor);
  Serial.println(estado_inte_at);
  if (estado_inte_at == estado_inte_ant) {
    alterar();
    if (estado_inte_at == 0) {
      estado_inte_ant = 1;
    } else if (estado_inte_at == 1) {
      estado_inte_ant = 0;
    }
  }

    //Simular Sinal via Mqtt
    estado_botao = digitalRead(botao);
    if (estado_botao == HIGH && (millis() - lastDebounceTime) > debounceDelay) {
      alterar();
      lastDebounceTime = millis();
    }
    Serial.println(estado_inte_at);
    Serial.println(estado_inte_ant);
    Serial.println(estado_botao);
    digitalWrite(led, estado_led);
}
