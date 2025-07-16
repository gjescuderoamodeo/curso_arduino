#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT11
#define PIN 15


DHT dht(DHTPIN, DHTTYPE);

float temperature = 0.0;
float humidity = 0.0;


void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(PIN, OUTPUT);

}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  digitalWrite(PIN, HIGH);
  delay(100);
  digitalWrite(PIN, LOW);

  Serial.printf("Temperatura: %.3f Humedad: %.3f \n", temperature, humidity);
  delay(5000); 
  }
