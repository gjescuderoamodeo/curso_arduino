#define VELOCITY 27
#define DIRPIN_1 13
#define DIRPIN_2 15

void setup() {
  Serial.begin(115200);

  pinMode(VELOCITY, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);
}

void loop() {
  //digitalWrite(VELOCITY, HIGH); //Encender motor
  Serial.println("Girando R");
  analogWrite(VELOCITY, 90);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  delay(2000);

  Serial.println("Paraó");
  digitalWrite(VELOCITY, LOW); //Apagar motor
  delay(2000);

  Serial.println("Girando L");
  //digitalWrite(VELOCITY, HIGH); //Encender motor
  analogWrite(VELOCITY, 100);
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0); 
  delay(2000);

  Serial.println("Paraó");
  digitalWrite(VELOCITY, LOW); //Apagar motor
  delay(2000); 
}
