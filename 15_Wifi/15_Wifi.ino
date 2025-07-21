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
  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());
}

void loop() {
  int redes = WiFi.scanNetworks();
  Serial.println(redes);

  for(int i=0;i<redes;i++){
    Serial.print(WiFi.RSSI(i));
    Serial.print("\t");
    Serial.print(WiFi.channel(i));
    Serial.print("\t");
    Serial.println(WiFi.SSID(i).c_str()); //Devuelve nombre red convertido a cadena
  }

}
