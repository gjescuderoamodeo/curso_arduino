#define LED 15


void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  /*digitalWrite(LED, HIGH);  
  delay(1000);
  digitalWrite(LED, LOW);  
  delay(1000);*/

  /*analogWrite(LED, 20);
  delay(500);
  analogWrite(LED, 120);
  delay(500);*/

  int power = 1000;
  do{
    analogWrite(LED, power);
    delay(500); 
    power-=50;
  }while(power!=0);

}
