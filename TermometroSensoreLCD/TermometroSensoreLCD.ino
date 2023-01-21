#include <LiquidCrystal.h>

const int PinSensore = A0;
const float TemperaturaBase = 20.0;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);

  lcd.print("Termometro");
  
  Serial.begin(9600);
  for(int NumeroPin = 2; NumeroPin<5; NumeroPin++){
    pinMode(NumeroPin, OUTPUT);
    digitalWrite(NumeroPin, LOW);
  }
}

void loop() {
  int ValoreDelSensore = analogRead(PinSensore);

  float Voltaggio = (ValoreDelSensore/1024.0) * 5.0;

  float Temperatura = (Voltaggio - .5) * 100;

  delay(2000);

  lcd.setCursor(0, 1);

  lcd.print(Temperatura);
}