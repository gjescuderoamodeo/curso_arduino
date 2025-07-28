#define VELOCITY 27
#define DIRPIN_1 13
#define DIRPIN_2 15

#define LED_ROJO 19
#define LED_VERDE 18
#define LED_AZUL 5

void setup() {
  Serial.begin(115200);

  pinMode(VELOCITY, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);  
}

void loop() {
  digitalWrite(VELOCITY, HIGH); //Encender motor
  Serial.println("Girando R");
  //analogWrite(VELOCITY, 200);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  delay(2000);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);

  Serial.println("Paraó");
  //analogWrite(VELOCITY, 0);
  digitalWrite(VELOCITY, LOW); //Apagar motor
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);  
  delay(2000);

  Serial.println("Girando L");
  digitalWrite(VELOCITY, HIGH); //Encender motor
  //analogWrite(VELOCITY, 150);
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0); 
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);  
  delay(2000);

  Serial.println("Paraó");
  //analogWrite(VELOCITY, 0);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);    
  digitalWrite(VELOCITY, LOW); //Apagar motor
  delay(2000); 
}
