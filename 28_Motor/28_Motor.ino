#define INPUT_1_VELOCITY 15
#define INPUT_2 13
#define ENABLE_1 27

void setup() {
  Serial.begin(115200);

  pinMode(INPUT_1_VELOCITY, OUTPUT);
  pinMode(INPUT_2, OUTPUT);
  pinMode(ENABLE_1, OUTPUT);
}

void loop() {
  digitalWrite(INPUT_1_VELOCITY, HIGH); //Encender motor
  digitalWrite(INPUT_2, 0);
  digitalWrite(ENABLE_1, 1);

  delay(5000);

  digitalWrite(INPUT_1_VELOCITY, LOW); //Apagar motor
  delay(2000);
}
