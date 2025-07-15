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
  if(buttonValue == LOW){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
  delay(100);
}
