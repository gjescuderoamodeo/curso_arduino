#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SCL 15
#define SDA 13
#define ADDR 0x3F

void setup() {
  Wire.begin(SDA,SCL);
  for(byte i = 0; i<120; i++){
    Wire.beginTransmission(i);
    if(Wire.endTransmission()==0){
      Serial.print("Direccion encontrada: ");
      Serial.print(i, DEC);
      Serial.print(" 0x");
      Serial.print(i, HEX);
      count++;
      delay(10);
    }
  }
  Serial.print("\n");
  Serial.println("Encontrados " + String(count));
}

void loop() {
  
}  


