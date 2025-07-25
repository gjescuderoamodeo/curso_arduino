#include <ESP32Servo.h>
#define PIN_SERVO 13

//handler
Servo miServo;
void setup() {
  miServo.setPeriodHertz(50);
  miServo.attach(PIN_SERVO,500,2500);
}

void loop() {
  //pá lante
  for(int i=0;i<300;i++){
    miServo.write(i);
    delay(20);
  }

  delay(200);

  //pá tras
  for(int i=300;i>0;i--){
    miServo.write(i);
    delay(20);
  }

  delay(200);
}
