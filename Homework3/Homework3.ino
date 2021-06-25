#define RELAY_PIN_1 13
#define RELAY_PIN_2 12
#define RELAY_PIN_3 11
#define RELAY_PIN_4 10
#define MASTER_RELAY 5

void setup() {
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  pinMode(MASTER_RELAY, OUTPUT);
}

void loop() {
  digitalWrite(MASTER_RELAY, HIGH);
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);
  digitalWrite(RELAY_PIN_4, HIGH);
}
