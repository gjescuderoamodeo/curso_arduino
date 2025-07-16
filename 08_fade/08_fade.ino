#define LED 15
#define LED2 12

int power = 255;
int power2 = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
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

  do{
    analogWrite(LED, power);
    analogWrite(LED2, power2);    
    delay(5); 
    power--;
    power2++;
  }while(power!=0 && power2!=255);

  delay(1000);

  do{
    power++;
    power2--;    
    analogWrite(LED, power);
    analogWrite(LED2, power2);
    delay(5); 
  }while(power!=255 && power2!=0);

  analogWrite(LED, 255);
  analogWrite(LED2, 0);
  delay(55);

}
