#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temperature = 0.0;
float humidity = 0.0;


void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  delay(5000);

  Serial.printf("Temperatura: %.3f Humedad: %.3f \n", temperature, humidity);
  }
