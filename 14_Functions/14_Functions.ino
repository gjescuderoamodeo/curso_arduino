void setup() {
  Serial.begin(115200);
  int values [] = {1,2,3,4,5,8,12,33};

  Serial.println(String(sum(values)));
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