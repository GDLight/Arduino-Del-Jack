int valoreSensore;
int sensoreBasso = 1023;
int sensoreAlto = 0;
const  int pinLed = 13;

void setup() {
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, HIGH);
  while (millis() < 5000){
    valoreSensore = analogRead(A0);
    if (valoreSensore > sensoreAlto) {
      sensoreAlto = valoreSensore;
    }
    if (valoreSensore < sensoreBasso) {
      sensoreBasso = valoreSensore;
    }
  }
  digitalWrite(pinLed, LOW);
}

void loop() {
  valoreSensore = analogRead(A0);
  int pitch =
  map(valoreSensore,sensoreBasso,sensoreAlto,50,4000);
  tone(8,pitch,20);
  delay(10);
}
