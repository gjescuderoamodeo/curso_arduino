#include <ESP32Servo.h>
#define PIN_SERVO 13

//handler
Servo miServo;

String entrada="";
String secreto="1234";

void setup() {
  Serial.begin(115200);
  miServo.setPeriodHertz(50);
  miServo.attach(PIN_SERVO,500,2500);
  miServo.write(0);
}

void loop() {
  //pedir imtroduzca código
  if(Serial.available()>0){
    entrada = Serial.readStringUntil("\n");
    entrada.trim();
    if(entrada==secreto){
      Serial.println("Clave correcta");
      miServo.write(90);
      delay(5000);
      Serial.println("Puerta cerrada");
      miServo.write(0);
    }else{
      Serial.println("Clave NO CORRECTA");
    }

  }
}
