//-add library:
//#include <stdio.h> | #include "stdio.h"

//-constants
//#define nombre_variable (mayusculas) valor | ejemplo: #define PI 3.14

#define PIN_LED 2
#define PIN_GREEN 12
int timesPassedLoop = 0;

void setup() {
  //velocidad comunicación mandar datos
  Serial.begin(115200);
  delay(100);// delay para que de tiempo se active el monitor serie, sino no se ve los prints
  Serial.println("Serial encencido");

  //definir si patilla entrada o de salida
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  /*digitalWrite(uint8_t pin, uint8_t val)
  permite escribir valores analogicos
  analogWrite(uint8_t pin, int value)
  
  HIGH=1
  LOW=0
  */
 
  Serial.println("veces pasado por el loop = " + String(timesPassedLoop));  
  delay(3000); 
  //Serial.println("encencido.");
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
  delay(500);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  delay(500);  
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
  delay(500); 
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  delay(500);
  digitalWrite(PIN_LED, HIGH);
  digitalWrite(PIN_GREEN, LOW);
  delay(500); 

  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_GREEN, LOW);
  delay(2000);
  digitalWrite(PIN_GREEN, HIGH);
  delay(2000); 
  digitalWrite(PIN_GREEN, LOW);
  delay(2000);
  digitalWrite(PIN_GREEN, HIGH);
  delay(2000);   
  digitalWrite(PIN_GREEN, LOW);
  delay(2000);
  digitalWrite(PIN_GREEN, HIGH);
  delay(2000); 
  digitalWrite(PIN_GREEN, LOW);
  

  delay(500);
  digitalWrite(PIN_GREEN, HIGH);
  delay(500);
  digitalWrite(PIN_GREEN, LOW);
  delay(500);  
  digitalWrite(PIN_GREEN, HIGH);
  delay(500); 
  digitalWrite(PIN_GREEN, LOW);
  delay(500);
  digitalWrite(PIN_GREEN, HIGH);
  delay(500); 

  //Serial.println("apagado.");
  timesPassedLoop++;



}
