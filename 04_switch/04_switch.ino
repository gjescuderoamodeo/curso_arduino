int dia=3;
String nombreDia = "";

void setup() {
  Serial.begin(115200);

  switch(dia){
    case 1: nombreDia="lunes";
      break;
    case 2 ... 7: nombreDia="jueves";
      break;  
  }

  Serial.println(nombreDia);

}

void loop() {
  // put your main code here, to run repeatedly:

}
