#define LED_ROJO 13
#define LED_VERDE 12
#define LED_AZUL 14

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);  
}

void loop() {
  //ROJO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //AMARILLO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //VERDE
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //AZUL
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, LOW);
  delay(200);

  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(2000);  
}
