#define VRX 4
#define VRY 0
#define SW 13

//leds
#define LED_UP 12
#define LED_DOWN 5
#define LED_RIGHT 19
#define LED_LEFT 15

int cero_x=1892;
int cero_y=2590;

void setup() {
  Serial.begin(115200);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP); 

  //LEDS
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);  
  pinMode(LED_LEFT, OUTPUT); 
}

void loop() {
  int value_x=analogRead(VRX);
  int value_y=analogRead(VRY);
  int value_z=digitalRead(SW);

  Serial.println("Value X: " + String(value_x) + " Value Y: " + String(value_y) + " Value Z: " + String(value_z));
  
  if(value_x-cero_x>20){ //DERECHA
    Serial.println("DERECHA: " + String(value_x-cero_x));
    cambioEstado(1);
  }

  if(value_x-cero_x<-20){ //IZQUIERDA
    Serial.println("IZQUIERDA: " + String(value_x-cero_x));
    cambioEstado(2);
  }

  if(value_y-cero_y>30){ //ABAJO
    Serial.println("ABAJO: " + String(value_y-cero_y));
    cambioEstado(4);
  }

  if(value_y-cero_y<-30){ //ARRIBA
    Serial.println("ARRIBA: " + String(value_y-cero_y));
    cambioEstado(3);
  }

  if(value_x>=1885 && value_y>=2585 && value_x>=1895 && value_y>=2600){ //NEUTRO
    Serial.println("NEUTRO: " + String(value_y-cero_y));
    cambioEstado(5);
  }

  if(!value_z){ //Boton central
    Serial.println("ALL");
    cambioEstado(6);
  }


  //delay(5000); 
}

void cambioEstado(int estadoNuevo){
  switch(estadoNuevo){
    case 1:
      derecha();
      delay(100);
      break;
    case 2:
      izquierda();
      delay(100);
      break;
    case 3:
      arriba();
      delay(100);
      break; 
    case 4:
      abajo();
      delay(100);
      break;
    case 5:
      neutro(); 
      break;
    case 6:
      todos();
      break;   
  }
}

void derecha(){
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_UP, LOW); 
  digitalWrite(LED_RIGHT, HIGH);
}

void arriba(){
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_UP, HIGH); 
  digitalWrite(LED_RIGHT, LOW);
}

void neutro(){
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_UP, LOW); 
  digitalWrite(LED_RIGHT, LOW);
}

void abajo(){
  digitalWrite(LED_DOWN, HIGH);
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_UP, LOW); 
  digitalWrite(LED_RIGHT, LOW);
}

void izquierda(){
  digitalWrite(LED_DOWN, LOW);
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_UP, LOW); 
  digitalWrite(LED_RIGHT, LOW);
}

void todos(){
  digitalWrite(LED_DOWN, HIGH);
  digitalWrite(LED_LEFT, HIGH);
  digitalWrite(LED_UP, HIGH); 
  digitalWrite(LED_RIGHT, HIGH);
}
