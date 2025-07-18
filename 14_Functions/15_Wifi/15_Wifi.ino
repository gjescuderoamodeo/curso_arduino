#include<WiFi.h>

const String ssid = "Aula 1";
const String pwd = "Horus.2025";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
