//LED_DISPLAY
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SCL 25
#define SDA 33
#define ADDR 0x3F

//handler
LiquidCrystal_I2C lcd(ADDR,16,2);

#define VELOCITY 27
#define DIRPIN_1 13
#define DIRPIN_2 15

#define LED_ROJO 19
#define LED_VERDE 18
#define LED_AZUL 5

#define DERECHA 1
#define IZQUIERDA 2
#define PARO 3


void setup() {
  Serial.begin(115200);

  Wire.begin(SDA,SCL);
  lcd.init();
  lcd.clear();
  lcd.backlight();


  pinMode(VELOCITY, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);  
}

void loop() {
  cambioEstado(DERECHA);
  delay(2000);
  cambioEstado(PARO);
  delay(2000);
  cambioEstado(IZQUIERDA);
  delay(2000);
  cambioEstado(PARO);
  delay(2000);
}

void cambioEstado(int estadoNuevo){
  switch(estadoNuevo){
    case DERECHA:
      derecha();
      break;
    case IZQUIERDA:
      izquierda();
      break;
    case PARO:
      parar();
      break; 
  }
}

void derecha(){
  digitalWrite(VELOCITY, HIGH); //Encender motor
  Serial.println("Girando R");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Girando R");
  //analogWrite(VELOCITY, 200);
  digitalWrite(DIRPIN_1, 0);
  digitalWrite(DIRPIN_2, 1);
  delay(2000);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AZUL, LOW);
}

void parar(){
  Serial.println("Parado");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Parado");
  //analogWrite(VELOCITY, 0);
  digitalWrite(VELOCITY, LOW); //Apagar motor

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, HIGH);  
  delay(2000);
}

void izquierda(){
  Serial.println("Girando L");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Girando L");
  digitalWrite(VELOCITY, HIGH); //Encender motor
  //analogWrite(VELOCITY, 150);
  digitalWrite(DIRPIN_1, 1);
  digitalWrite(DIRPIN_2, 0); 
  digitalWrite(LED_ROJO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);  
  delay(2000);
}
