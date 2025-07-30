/*OTA:

user:admin
psswd:f@d64i"$XpkEq}+ | cursoArduino@1
http://192.168.0.25:18083/
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <PubSubClient.h>

//MQQT
WiFiClient espClient;
PubSubClient client(espClient);

String mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

String mqtt_topic_sub="curso_arduino/#";
String mqtt_topic_pub="curso_arduino/guillermo";
String mqtt_client_id=" ESP_";

//Wifi
const String ssid = "Aula 1";
const String pwd = "Horus.2025";

WiFiClient clientWifi;
HTTPClient http;

String servidor = "http://192.168.0.56:5000/datos";


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
