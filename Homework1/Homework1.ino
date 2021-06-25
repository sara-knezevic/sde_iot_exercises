#define CAR_RED 12
#define CAR_YELLOW 11
#define CAR_GREEN 10
#define PED_RED 8
#define PED_GREEN 9
#define BUTTON 2

void ISRFunction() {
  carStop();
  pedestrianButton();
  carSet();
}

void pedestrianButton() {
  digitalWrite(PED_RED, LOW);
  digitalWrite(PED_GREEN, HIGH);
  delay(1000000); // 10 seconds
  digitalWrite(PED_GREEN, LOW);
  digitalWrite(PED_RED, HIGH);
  delay(100000);
}

void carStop() {
  digitalWrite(CAR_GREEN, LOW);
  digitalWrite(CAR_YELLOW, HIGH);
  delay(200000); // 2 seconds
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_RED, HIGH);
  delay(100000); // 1 second before pedestrian green
}

void carSet() {
  digitalWrite(CAR_RED, LOW);
  digitalWrite(CAR_YELLOW, HIGH);
  delay(200000); // 2 seconds
  digitalWrite(CAR_YELLOW, LOW);
  carGo();
}

void carGo() {
  digitalWrite(PED_RED, HIGH);
  digitalWrite(CAR_GREEN, HIGH);
  delay(1000000); // 10 seconds button block
}

void setup() {
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), ISRFunction, FALLING);

  carGo();
}

void loop() {}
