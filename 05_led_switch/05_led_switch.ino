#define BUTTON 13
#define LED 4

int buttonValue = LOW;
int state = LOW;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  buttonValue = digitalRead(BUTTON);
  //if button press, change state
  if(buttonValue == LOW){
    if(state==HIGH){
      state=LOW;
    }else {
      state=HIGH;
    }
  }  

  if(state == HIGH){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
  delay(100);
}
