/*OTA:

user:admin
psswd:f@d64i"$XpkEq}+ | cursoArduino@1
http://192.168.0.25:18083/
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

//MQQT
WiFiClient espClient;
PubSubClient client(espClient);

char* mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

char* mqtt_topic_sub="curso_arduino/#";
char* mqtt_topic_pub="curso_arduino/guillermo";

char* mqtt_client_id=" ESP_PEPE";

static unsigned long lastMsg = 0;

//Wifi
const String ssid = "Aula 1";
const String pwd = "Horus.2025";

WiFiClient clientWifi;
HTTPClient http;

String servidor = "http://192.168.0.56:5000/datos";

//temperature
DHT dht(DHTPIN, DHTTYPE);
float temperature = 0.0;
float humidity = 0.0;

char temStr[8];
char humStr[8];


void setup() {
  Serial.begin(115200);
  dht.begin();
  //conexión Wifi
  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());

  //MQTT
  client.setServer(mqtt_server,mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if(!client.connected()){
    reconnect();
  }
  client.loop();
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  dtostrf(temperature, 1,2, temStr);
  dtostrf(humidity, 1,2, humStr);

  client.publish("curso_arduino/guillermo/temperatura", temStr);
  client.publish("curso_arduino/guillermo/humedad", humStr);

  Serial.println("Temperatura: " + String(temStr));
  Serial.println("Humedad: " + String(humStr));

  delay(5000);
}

//funciones
void callback(String topic, byte* payload, unsigned int length){
  Serial.print("Mensaje recibido en [");
  Serial.print(topic);
  Serial.print("]:");

  for(int i=0; i<length; i++){
    Serial.print((String)payload[i]);
  }
  Serial.print("");
}

void reconnect(){
  while(!client.connected()){
    Serial.println("Reconectando...");
    if(client.connect(mqtt_client_id)){
      Serial.println("Conectado a MQTT");
      client.subscribe(mqtt_topic_sub);
    }else{
      Serial.println("Fallo en la conexión");
      Serial.println("Error: " + client.state());
      delay(5000);
    }
  }
}
