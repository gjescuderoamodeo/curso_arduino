#include <WiFi.h>
#include <WebServer.h>

const String ssid = "Aula 1";
const String pwd = "Horus.2025";
WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());

  server.begin();
}

void loop() {
}
