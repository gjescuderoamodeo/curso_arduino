#define VRX 4
#define VRY 0
#define SW 13

int cero_x=1892;
int cero_y=2590;

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
  
  if(value_x-cero_x>10){ //DERECHA
    Serial.println("DERECHA: " + String(value_x-cero_x));
  }

  if(value_x-cero_x<-10){ //IZQUIERDA
    Serial.println("IZQUIERDA: " + String(value_x-cero_x));
  }

  if(value_y-cero_y>10){ //ABAJO
    Serial.println("ABAJO: " + String(value_y-cero_y));
  }

  if(value_y-cero_y<-10){ //ARRIBA
    Serial.println("ARRIBA: " + String(value_y-cero_y));
  }


  delay(5000); 
}
