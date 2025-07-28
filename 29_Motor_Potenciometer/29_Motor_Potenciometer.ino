#define VELOCITY 27
#define DIRPIN_1 13
#define DIRPIN_2 15
#define POTEN 4

int potValue = 0;

void setup() {
  Serial.begin(115200);

  pinMode(VELOCITY, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  //potenciometros
  pinMode(POTEN, INPUT);
}

void loop() {
  int valorVel = 0;

  //0-4096
  potValue=analogRead(POTEN);
  valorVel = map(potValue,0,4096,90,500);

  digitalWrite(VELOCITY, HIGH); //Encender motor
  analogWrite(VELOCITY, valorVel);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);

  Serial.println(valorVel);
}