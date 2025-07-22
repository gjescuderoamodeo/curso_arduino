#define echo 15
#define trigger 13
#define maxDist 700 //cm
#define led 0

float distancia = 0.0;
float timeOut = maxDist * 60;
int velSound = 340;
int ledValue = 0;


void setup() {
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  distancia = getSonar();
  Serial.println("Distancia: " + String(distancia));
  delay(10000); 
}

float getSonar(){
  unsigned long int pingTime = 0; //número entero grande siempre positivo
  float dist = 0.0;

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);

  pingTime = pulseIn(echo, HIGH, timeOut);

  Serial.println("Ping time: " + String(pingTime));

  dist = (float) pingTime * velSound / 2 / 10000;

  //valor convertido
  ledValue = map(dist,0,350,0,255);
  analogWrite(led, 255-ledValue);

  return dist;
}
