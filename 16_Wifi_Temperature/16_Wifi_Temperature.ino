#include<WiFi.h>
#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT11

//Wifi
const String ssid = "Aula 1";
const String pwd = "Horus.2025";

//temperature
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());

  dht.begin();
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  delay(100);

}
