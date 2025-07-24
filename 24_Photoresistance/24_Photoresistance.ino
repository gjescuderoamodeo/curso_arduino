#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SCL 15
#define SDA 13
#define ADDR 0x3F
#define RESISTANCE 0

int ledValue = 0;
int resValue = 0;

//handler
LiquidCrystal_I2C lcd(ADDR,16,2);

void setup() {
  Wire.begin(SDA,SCL);
  pinMode(RESISTANCE, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  lcd.clear();
  //0-4096
  resValue=analogRead(RESISTANCE);

  //valor convertido
  ledValue = map(resValue,0,4096,0,255);

  lcd.setCursor(0,0);
  lcd.print("resistence value");
  lcd.setCursor(6,1);
  lcd.print(resValue);
  delay(3000);
}  

