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
    state=!state;
    digitalWrite(LED, state);
  }  

  delay(100);
}
