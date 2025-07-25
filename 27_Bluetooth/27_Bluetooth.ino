#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#define PIN_SERVO 13
#define PIN_RED 0
#define PIN_GREEN 15

//handler
Servo miServo;

String entrada="";
String secreto="1234";

BluetoothSerial serialBT;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  miServo.setPeriodHertz(50);
  miServo.attach(PIN_SERVO,500,2500);
  miServo.write(0);
  serialBT.begin("BT_Pepe");
  Serial.println("Dispositivo listo para emparejarse");

}

void loop() {
  //pedir introduzca código
  if(serialBT.available()){
    entrada = serialBT.readStringUntil('\n');
    entrada.trim();
    if(entrada==secreto){
      serialBT.println("Clave correcta");
      miServo.write(90);
      analogWrite(PIN_GREEN, HIGHT);
      analogWrite(PIN_RED, LOW);
      delay(5000);
      serialBT.println("Puerta cerrada");
      analogWrite(PIN_GREEN, LOW);
      analogWrite(PIN_RED, HIGHT);
      miServo.write(0);
    }else{
      serialBT.println("Clave NO CORRECTA");
    }
  }
}
