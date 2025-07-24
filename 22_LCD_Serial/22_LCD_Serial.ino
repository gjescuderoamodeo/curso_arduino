#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SCL 15
#define SDA 13
#define ADDR 0x3F

//handler
LiquidCrystal_I2C lcd(ADDR,16,2);

byte corazon[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA,SCL);
  //Wire.beginTransmission(ADDR);

  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  if(Serial.available()){
    delay(100);
    lcd.clear();

    while(Serial.available()>0){
      lcd.write(Serial.read());
    }
  }
}  

