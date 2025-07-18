void setup() {
  Serial.begin(115200);
  int values [] = {1,2,3,4,5,8,12,33};
  String cadena = "Arduino";

  Serial.println(String(sum(values)));
  Serial.println(String(longitudCadena(cadena)));
}

void loop() {
  // put your main code here, to run repeatedly:

}

//Functions
int sum(int values[]){
  int sumTotal = 0;
  for(int i=0;i<8;i++){
    sumTotal += values[i]; 
  }

  return sumTotal;
}

//funcion calcule longitud de cadena
int longitudCadena(String cadena){
  for(int longitud=0;;longitud++){
    if(cadena[longitud]==NULL){
      return longitud;
    }
  }
}
