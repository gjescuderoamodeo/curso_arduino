#include <WiFi.h>
#include <WebServer.h>

#define PIN_LED 2

const String ssid = "Aula 1";
const String pwd = "Horus.2025";
WebServer server(80);

//páginas
String home = "<!DOCTYPE html><html lang=\"es\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Curso Arduino</title><style>body{background-color:#000;color:#adff2f;text-align:center;font-style:italic;font-family:Verdana,Geneva,Tahoma,sans-serif}table{display:inline}td{width:1%;height:50px;background-color:#ff4500}</style><body><h1>Curso Arduino</h1><table><tr><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td><td>6</td></tr><tr><td>7</td><td>8</td><td>9</td><td>10</td><td>11</td><td>12</td></tr></table></body></html>";
void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n mi Ip local:");
  Serial.print(WiFi.localIP());

  //solicitudes web
  server.on("/",handle_OnConnect);

  server.begin();
}

void loop() {
  server.handleClient();
}

//funciones de respuesta a las páginas web
void handle_OnConnect(){
  server.send(200,"text/html",home);
}

void setLed(){
  if(digitalRead(PIN_LED)!=LOW){
    digitalWrite(PIN_LED, LOW);
    delay(500); 
  }else{
    digitalWrite(PIN_LED, HIGH);
    delay(500);
  }
}
