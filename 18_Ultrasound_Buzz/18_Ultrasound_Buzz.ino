#define echo 15
#define trigger 13
#define maxDist 700 //cm
#define buzz 0

float distancia = 0.0;
float timeOut = maxDist * 60;
int velSound = 340;
int buzzValue = 0;
int intervalos[] = {10,20,30,40,50,60,70,80,90,100};

void setup() {
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  distancia = getSonar();

  if(getIntervalo(distancia) <= 100){
    pitar(getIntervalo(distancia));
  }

  Serial.println("Distancia: " + String(distancia));
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
  buzzValue = map(dist,0,350,0,255);
  analogWrite(buzz, 255-buzzValue);

  return dist;
}

int getIntervalo(float lejos){
  int salida = 1000;
  for(int i=0;i<10;i++){
    if(lejos<intervalos[i]){
      salida = intervalos[i];
      break;
    }
  }
  return salida;
}

void pitar(int umbral){
  for(int i=0;i<5;i++){
    digitalWrite(buzz, HIGH);
    delay(50);
    digitalWrite(buzz, LOW);
    delay(10*umbral);
  }
}
