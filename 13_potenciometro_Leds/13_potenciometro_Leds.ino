#define LED_ROJO 14
#define LED_VERDE 12
#define LED_AZUL 13
#define POTEN1 15
#define POTEN2 4
#define POTEN3 27

int potValue1 = 0;
int potValue2 = 0;
int potValue3 = 0;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT); 
  pinMode(POTEN1, INPUT);
  pinMode(POTEN2, INPUT); 
  pinMode(POTEN3, INPUT); 
}

void loop() {
  //0-4096
  potValue1=analogRead(POTEN1);
  potValue2=analogRead(POTEN2);
  potValue3=analogRead(POTEN3);

  int r = 0;   
  int g = 0; 
  int b = 0; 

  r = map(potValue1,0,4096,0,255);
  g = map(potValue2,0,4096,0,255);
  b = map(potValue3,0,4096,0,255);

  analogWrite(LED_ROJO, r);
  analogWrite(LED_VERDE, g);
  analogWrite(LED_AZUL, b);

}
