#define BUTTON 13
#define LED 4
#define ZUM 15

int buttonValue = LOW;
int state = LOW;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(ZUM, OUTPUT);
}

void loop() {
  buttonValue = digitalRead(BUTTON);
  //if button press, change state
  /*if(buttonValue == LOW){
    state=!state;
    digitalWrite(LED, state);
  }  

  delay(100);*/
  if(buttonValue == LOW){
    digitalWrite(LED, HIGH);
    digitalWrite(ZUM, HIGH);
  }else{
    digitalWrite(LED, LOW);
    digitalWrite(ZUM, LOW);
  }
  delay(100);
}
