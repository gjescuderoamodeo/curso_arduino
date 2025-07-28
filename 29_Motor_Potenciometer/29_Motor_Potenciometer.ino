#define VELOCITY 27
#define DIRPIN_1 13
#define DIRPIN_2 15
#define POTEN 15

#define DERECHA 1
#define IZQUIERDA 2
#define PARO 3

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
  int r = 0;
  
  //0-4096
  potValue=analogRead(POTEN);
  r = map(potValue,0,4096,0,255);
  analogWrite(VELOCITY, r);
}