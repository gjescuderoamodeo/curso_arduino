#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <DHT.h>

#define DHTPIN 18
#define DHTTYPE DHT11

#define SCL 15
#define SDA 13
#define ADDR 0x3F

//temperature
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
float humidity = 0.0;

//handler
LiquidCrystal_I2C lcd(ADDR,16,2);


void setup() {
  Serial.begin(115200);
  Wire.begin(SDA,SCL);
  dht.begin();

  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {

  
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  delay(100);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura:" + String(temperature));
  lcd.setCursor(0,1);
  lcd.print("Humedad:" + String(humidity));
  delay(5000);


}  

