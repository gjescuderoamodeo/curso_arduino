//-add library:
//#include <stdio.h> | #include "stdio.h"

//-constants
//#define nombre_variable (mayusculas) valor | ejemplo: #define PI 3.14

#define PIN_LED 2

void setup() {
  //velocidad comunicación mandar datos
  Serial.begin(115200);
  delay(100);// delay para que de tiempo se active el monitor serie, sino no se ve los prints
  Serial.println("Serial encencido");

  //definir si patilla entrada o de salida
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  /*digitalWrite(uint8_t pin, uint8_t val)
  permite escribir valores analogicos
  analogWrite(uint8_t pin, int value)
  
  HIGH=1
  LOW=0
  */
  Serial.println("encencido.");

  delay(3000); 
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
  delay(500);  
  digitalWrite(PIN_LED, HIGH);
  delay(500); 
  digitalWrite(PIN_LED, LOW);
  delay(500);
  digitalWrite(PIN_LED, HIGH);
  delay(500); 

  digitalWrite(PIN_LED, LOW);
  delay(2000);
  digitalWrite(PIN_LED, HIGH);
  delay(2000); 
  digitalWrite(PIN_LED, LOW);
  delay(2000);
  digitalWrite(PIN_LED, HIGH);
  delay(2000);   
  digitalWrite(PIN_LED, LOW);
  delay(2000);
  digitalWrite(PIN_LED, HIGH);
  delay(2000); 
  digitalWrite(PIN_LED, LOW);

  Serial.println("apagado.");




}
