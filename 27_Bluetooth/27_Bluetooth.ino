#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#define PIN_SERVO 13

//handler
Servo miServo;

String entrada="";
String secreto="1234";

BluetoothSerial serialBT;

void setup() {
  Serial.begin(115200);
  miServo.setPeriodHertz(50);
  miServo.attach(PIN_SERVO,500,2500);
  miServo.write(0);
  serialBT.begin("BT_Pepe");
  Serial.println("Dispositivo listo para emparejarse");

}

void loop() {
  //pedir introduzca código
  if(Serial.available()){
    serialBT.write(Serial.read());
    
    //read from bluetooth
    if(serialBT.available()){
      Serial.write(serialBT.read());
    }

    entrada = Serial.readStringUntil('\n');
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
