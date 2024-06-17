#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Endereço do LCD 0x27 para um display de 20 caracteres e 4 linhas

int pinoJoystickHorz = A1;
int pinoPot = A2;
int pinoLEDVerde = 11;
int pinoLEDAmarelo = 12;
int pinoLEDVermelho = 13;

float velocidade = 0;
float bateria = 100.0; // Bateria inicial em 100%
int maxVelocidade = 290; // Velocidade máxima em km/h

void setup() {
  lcd.begin(20, 4);
  lcd.backlight();
  
  pinMode(pinoLEDVerde, OUTPUT);
  pinMode(pinoLEDAmarelo, OUTPUT);
  pinMode(pinoLEDVermelho, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int direcaoVolante = analogRead(pinoJoystickHorz);
  int valorPot = analogRead(pinoPot);

  velocidade = map(valorPot, 0, 1023, 0, maxVelocidade);
  
  // Calcula o nível da bateria
  if (velocidade > 0) {
    bateria -= 1.05; // Reduzir a bateria ao acelerar
    if (bateria < 0) bateria = 0;
  } else {
    bateria += 2.05; // Recarregar a bateria ao frear
    if (bateria > 100) bateria = 100;
  }

  // Controla os LEDs
  if (velocidade > 0) {
    digitalWrite(pinoLEDVerde, HIGH);
    digitalWrite(pinoLEDAmarelo, LOW);
  } else {
    digitalWrite(pinoLEDVerde, LOW);
    digitalWrite(pinoLEDAmarelo, HIGH);
  }

  if (bateria == 0) {
    digitalWrite(pinoLEDVermelho, HIGH);
  } else {
    digitalWrite(pinoLEDVermelho, LOW);
  }

  // Determinar a direção com base no joystick
  String direcao;
  if (direcaoVolante < 400) {
    direcao = "Esquerda";
  } else if (direcaoVolante > 600) {
    direcao = "Direita";
  } else {
    direcao = "Centro";
  }
  
  // Exibir as informações no LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Velocidade: ");
  lcd.print(velocidade);
  lcd.print(" km/h");
  lcd.setCursor(0, 1);
  lcd.print("Bateria: ");
  lcd.print(bateria);
  lcd.print(" %");
  lcd.setCursor(0, 2);
  lcd.print("Direcao: ");
  lcd.print(direcao);

  // Exibir estado da bateria
  lcd.setCursor(0, 3);
  if (digitalRead(pinoLEDVermelho) == HIGH) {
    lcd.print("Bateria Vazia");
  } else if (digitalRead(pinoLEDAmarelo) == HIGH) {
    lcd.print("Recarregando");
  }

  delay(200);
}
