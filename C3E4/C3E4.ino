#define RELAY_PIN_1 13
#define RELAY_PIN_2 12
#define RELAY_PIN_3 11
#define MASTER_RELAY 5

void setup() {
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(MASTER_RELAY, OUTPUT);
}

int room = 1;
void loop() {
  switch (room) {
    case 1:
      {
        digitalWrite(RELAY_PIN_1, HIGH);
        digitalWrite(RELAY_PIN_2, HIGH);
        digitalWrite(RELAY_PIN_3, HIGH);
        digitalWrite(MASTER_RELAY, HIGH);
        room = 2;
        delay(1000);
      } break;
     case 2:
      {
        digitalWrite(RELAY_PIN_1, HIGH);
        digitalWrite(RELAY_PIN_2, HIGH);
        digitalWrite(RELAY_PIN_3, HIGH);
        digitalWrite(MASTER_RELAY, LOW);
        room = 3;
        delay(1000);
      } break;
     case 3:
      {
        digitalWrite(RELAY_PIN_1, HIGH);
        digitalWrite(RELAY_PIN_2, LOW);
        digitalWrite(RELAY_PIN_3, HIGH);
        digitalWrite(MASTER_RELAY, LOW);
        room = 4;
        delay(1000);
      } break;
     case 4: 
      {
        digitalWrite(RELAY_PIN_1, HIGH);
        digitalWrite(RELAY_PIN_2, LOW);
        digitalWrite(RELAY_PIN_3, HIGH);
        digitalWrite(MASTER_RELAY, HIGH);
        room = 1;
        delay(1000);
      } break;
  }
}
