#define LED 12
#define POTEN 15

int potValue = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(POTEN, INPUT);
}

void loop() {
  //0-4096
  potValue=analogRead(POTEN);

  analogWrite(LED, potValue);

}
