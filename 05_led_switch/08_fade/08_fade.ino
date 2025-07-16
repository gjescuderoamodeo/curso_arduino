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

  int power = 2000;
  do{
    analogWrite(LED, power);
    delay(500); 
    power-=50;
  }while(power!=0);

  delay(500);
  
  if(power==0){
    do{
      analogWrite(LED, power);
      delay(500); 
      power+=50;
    }while(power!=2000);
  }


}
