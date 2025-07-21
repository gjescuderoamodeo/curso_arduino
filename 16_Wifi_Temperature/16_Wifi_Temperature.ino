#include <WiFi.h>
#include <DHT.h>
#include <HTTPClient.h>
#define DHTPIN 12
#define DHTTYPE DHT22

//Wifi
const String ssid = "Aula 1";
const String pwd = "Horus.2025";

const WiFiClient clientWifi;
const HTTPClient http;

String servidor = "192.168.0.25:5000/datos";

//temperature
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) {
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

  Serial.printf("Temperatura: %.3f Humedad: %.3f \n", temperature, humidity);
  delay(5000);
}

//funciones
void postData(float temperature, float readHumidity, String person){
  String parametros = "temp="+ 
  String(temperature) + "&hum=" + 
  String(humidity) + "&persona=" person;

  if (WiFi.status() == WL_CONNECTED) {
  statements
  }
}
