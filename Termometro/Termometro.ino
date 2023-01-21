const int PinSensore = A0;
const float TemperaturaBase = 20.0;

void setup() {
  Serial.begin(9600);
  for(int NumeroPin = 2; NumeroPin<5; NumeroPin++){
    pinMode(NumeroPin, OUTPUT);
    digitalWrite(NumeroPin, LOW);
  }
}

void loop() {
  int ValoreDelSensore = analogRead(PinSensore);
  Serial.print("Valore del sensore: ");
  Serial.print(ValoreDelSensore);
  float Voltaggio = (ValoreDelSensore/1024.0) * 5.0;
  Serial.print(", Volts:");
  Serial.print(Voltaggio);
  Serial.print(", Gradi Centigradi: ");
  float Temperatura = (Voltaggio - .5) * 100;
  Serial.println(Temperatura);
  if(Temperatura < TemperaturaBase){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (Temperatura >= TemperaturaBase+2 && Temperatura < TemperaturaBase+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if (Temperatura >= TemperaturaBase+4 && Temperatura < TemperaturaBase+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if (Temperatura >= TemperaturaBase+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
