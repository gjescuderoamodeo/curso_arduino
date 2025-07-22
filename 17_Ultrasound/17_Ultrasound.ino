#define echo 15
#define trigger 13
#define maxDist 700 //cm

float distancia = 0.0;
float timeOut = maxDist * 60;
int velSound = 340;

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {


  
  delay(5000); 
}

float getSonar(){
  unsigned long int pingTime = 0; //número entero grande siempre positivo
  float dist = 0.0;

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);

  pingTime = pulseIn(echo, HIGH, timeOut);

  Serial.println("Ping time: ");

  return;
}
