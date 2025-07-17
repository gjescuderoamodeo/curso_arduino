#define LED 12
#define POTEN 15

int ledValue = 0;
int potValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POTEN, INPUT);
}

void loop() {
  //0-4096
  potValue=analogRead(POTEN);

  //valor convertido
  ledValue = map(potValue,0,4096,0,255);
  analogWrite(LED, ledValue);

}
