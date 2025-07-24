#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SCL 15
#define SDA 13
#define ADDR 0x3F

//handler
LiquidCrystal_I2C lcd(ADDR,16,2);

void setup() {
  Wire.begin(SDA,SCL);
  //Wire.beginTransmission(ADDR);

  lcd.init();
  //lcd.noBacklight();
  //delay(1000);
  lcd.backlight();
  //delay(1000);
  //lcd.blink();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hola Mundo");
  lcd.setCursor(0, 1);
  lcd.print("Curso arduino");

  //pinMode(SCL, OUTPUT);
  //pinMode(SDA, OUTPUT);
}

void loop() {
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
}  

