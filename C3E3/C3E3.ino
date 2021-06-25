#define RELAY_PIN 13
#define BUTTON 2

int input_value = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input_value = !digitalRead(BUTTON);
  digitalWrite(RELAY_PIN, input_value);
}
