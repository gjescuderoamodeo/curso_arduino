#define LED 4
//carpeta comp https://drive.google.com/drive/folders/1tm3B6GzcZ989xbgSoWEtjIHVgQmGomG9
void setup() {
  //bucles controlados por contador
  //for(inicio, fin, paso)
  //bucles infinitos
  //while
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  for(int i=150 ; i>=0 ;i--){
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW); 
    delay(i);
  }
}
