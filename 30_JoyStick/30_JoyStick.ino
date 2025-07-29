#define VRX 4
#define VRY 0
#define SW 13

void setup() {
  Serial.begin(115200);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP); 

}

void loop() {
  int value_x=analogRead(VRX);
  int value_y=analogRead(VRY);
  int value_z=digitalRead(SW);

  Serial.println("Value X: " + String(value_x) + " Value Y: " + String(value_y) + " Value Z: " + String(value_z));
  
  delay(5000); 
}
