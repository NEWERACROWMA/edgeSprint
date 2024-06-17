#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TM1637.h>

int CLK = 13;
int DIO = 12;
int buzzer = 11;

TM1637 tm(CLK, DIO);

LiquidCrystal_I2C lcd(0x27, 20, 4);

int horas = 0;
int minutos = 0;

void setup() {
  tm.init();
  tm.set(BRIGHT_TYPICAL);

  lcd.init();
  lcd.backlight();

  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Atualizar o display com horas e minutos
  tm.display(0, (horas / 10) % 10); // Dígito das dezenas de horas
  tm.display(1, horas % 10); // Dígito das unidades de horas
  tm.display(2, (minutos / 10) % 10); // Dígito das dezenas de minutos
  tm.display(3, minutos % 10); // Dígito das unidades de minutos

  lcd.setCursor(0, 0);
  lcd.print("Tempo: ");
  lcd.print(horas);
  lcd.print("h ");
  lcd.print(minutos);
  lcd.print("m ");

  checarTipoDrop();

  delay(6); //velocidade do cronometro
  minutos++;
  if (minutos == 60) {
    minutos = 0;
    horas++;
    if (horas == 24) {
      horas = 0;
    }
  }
}

void checarTipoDrop() {
  // Verifica se o drop ainda não foi notificado e se o tempo é adequado para notificar
  if (horas == 3 && minutos == 0) {
    notificarDrop("Comum", 1);
  } else if (horas == 6 && minutos == 0) {
    notificarDrop("Raro ", 2);
  } else if (horas == 9 && minutos == 0) {
    notificarDrop("Epico", 3);
  }
}

void notificarDrop(char* raridade, int tipoDrop) {
  lcd.setCursor(0, 1);
  lcd.print("Drop Disponivel: ");
  lcd.setCursor(0, 2);
  lcd.print(raridade);

  // Emite um som no buzzer com base no tipo de drop
  int musica[] = {0, 0, 0, 0}; // Frequências padrão
  int tempo[] = {200, 200, 200, 200}; // Duração de cada nota

  if (tipoDrop == 1) {
    musica[0] = 262;
    musica[1] = 294;
    musica[2] = 330;
    musica[3] = 349;
  } else if (tipoDrop == 2) {
    musica[0] = 392;
    musica[1] = 440;
    musica[2] = 494;
    musica[3] = 523;
  } else if (tipoDrop == 3) {
    musica[0] = 523;
    musica[1] = 587;
    musica[2] = 659;
    musica[3] = 698;
  }

  tocarSom(musica, tempo, 4);
}

void tocarSom(int musica[], int tempo[], int length) {
  for (int i = 0; i < length; i++) {
    tone(buzzer, musica[i], tempo[i]);
    delay(tempo[i] + 50);
  }
  noTone(buzzer);
}