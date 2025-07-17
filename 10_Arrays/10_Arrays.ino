int numeros [5];
int numeros2[] = {1,2,3,4,5};

void setup() {
  Serial.begin(115200);
  delay(100);
  for(int i=0;i<5;i++){
    numeros[i]=numeros2[i];
  }

  for(int i=0;i<5;i++){
    Serial.println(numeros[i]);
  }
  


}

void loop() {
}
