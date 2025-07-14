#define PIN_RED 4
#define PIN_BLUE 13
#define PIN_GREEN 12
String ledColor = "";

void setup() {
  //velocidad comunicación mandar datos
  Serial.begin(115200);

  //definir si patilla entrada o de salida
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);  
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {
  /*digitalWrite(uint8_t pin, uint8_t val)
  permite escribir valores analogicos
  analogWrite(uint8_t pin, int value)
  
  HIGH=1
  LOW=0
  */
 
  Serial.println("Rojo encendio"); 
  digitalWrite(PIN_RED, HIGH);
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_GREEN, LOW);
  delay(500);
  Serial.println("Azul encendio"); 
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_BLUE, HIGH);
  digitalWrite(PIN_GREEN, LOW);
  delay(500);  
  Serial.println("Verde encendio"); 
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_BLUE, LOW);
  digitalWrite(PIN_GREEN, HIGH);
  delay(500); 
}
