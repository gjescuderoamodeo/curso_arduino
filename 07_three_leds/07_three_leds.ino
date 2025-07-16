#define LED_ROJO 13
#define LED_VERDE 12
#define LED_AZUL 14

#include <time.h>
#include <stdlib.h>

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);  
}

void loop() {
  int r = 0;   
  int g = 0; 
  int b = 0; 

  for(;;){
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);

    analogWrite(LED_ROJO, r);
    analogWrite(LED_VERDE, g);
    analogWrite(LED_AZUL, b);
    delay(1000);
  }

  //ROJO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //AMARILLO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //VERDE
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);
  //AZUL
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);
  //MAGENTA
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);
 //CIAN
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);  
  //BLANCO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  delay(1000);


  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(2000);  
//----------------------------
//ROJO
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(1000);

}
