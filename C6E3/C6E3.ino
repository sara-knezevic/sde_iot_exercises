#define PIN_ENA 9
#define PIN_IN1 10
#define PIN_IN2 11

#define PIN_ENB 6
#define PIN_IN3 4
#define PIN_IN4 5

#define BUTTON 2

bool directionPositive = true;
void buttonPressISR() {
  directionPositive = !directionPositive;
}

void setup() {
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);

  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressISR, FALLING);
}

void loop() {
  analogWrite(PIN_ENA, 255); // == PWM
  analogWrite(PIN_ENB, 255); // == PWM

  // DIRECTION NEGATIVE HIGH LOW
  // DIRECTION POSITIVE LOW HIGH
  if (directionPositive) {
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
    digitalWrite(PIN_IN3, LOW);
    digitalWrite(PIN_IN4, HIGH);
  } else {
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
  }
}
