// INCLUSÃO DE BIBLIOTECA
#include <IRremote.h>

#define pinSensor 11
#define frequencia 38
int pin_botao = 5;
bool estado_ant;
int estado = 0;
// INSTANCIANDO OBJETOS
IRsend irsend;
IRrecv sensorIR (pinSensor);
decode_results   comando;

//unsigned int valor[] = {8950, -4450, 600, -500, 600, -500, 600, -500, 600, -500, 600, -550, 550, -550, 550, -550, 550, -550, 600, -1650, 550, -1650, 600, -1650, 600, -1650, 550, -1700, 550, -1650, 600, -1650, 600, -1650, 550, -550, 600, -500, 600, -1650, 550, -550, 550, -550, 600, -500, 600, -500, 600, -500, 550, -1700, 550, -1700, 550, -550, 550, -1700, 550, -1650, 600, -1650, 600, -1650, 550, -1650, 600};

void setup() {

  Serial.begin(9600);

  // HABILITANDO SENSOR IR
  sensorIR.enableIRIn();
  Serial.println("Sensor IR Habilitado");
  pinMode(pin_botao, INPUT);
  pinMode(3, OUTPUT);
  estado_ant = !digitalRead(pin_botao);
}

void loop() {
  // QUANDO RECEBER UM COMANDO DO CONTROLE INICIA O BLOCO
  estado = digitalRead(pin_botao);
  if(estado == estado_ant){
    estado_ant = !estado;
    irsend.sendNEC(0xFF20DF,32);
    //irsend.sendRaw(valor, sizeof(valor) / sizeof(valor[0]), frequencia);
    Serial.println("OK!");
    //delay(2000);
  }
  if (sensorIR.decode(&comando)) {
    Serial.println(comando.value, HEX);
    sensorIR.resume();// ENCERRA PARA AGUARDAR NOVO COMANDO
  }
  delay(10);  
}
