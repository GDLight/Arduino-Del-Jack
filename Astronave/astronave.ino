#define LED1 3
#define LED2 4
#define LED3 5
#define POWER 2

int switchState = LOW;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(POWER, INPUT);
}

void loop() {
  switchState = digitalRead(POWER);

  if (switchState == LOW){
    // Il pulsante non e' premuto
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  } else {
    // Il pulsante e' premuto
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);

    delay(100);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    delay(100);
  }
}
