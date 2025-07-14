int nota = 0;

void setup() {
  Serial.begin(115200);
  delay(500);
  if(Serial.available() > 0) {
    
    if(nota >= 9) {
      Serial.println("Sobresaliente");
    } else if(nota >= 7) {
      Serial.println("Notable");
    } else if(nota >= 5) {
      Serial.println("Aprobado");
    } else {
      Serial.println("Suspenso");
    }
  }
}

void loop() {
  
}