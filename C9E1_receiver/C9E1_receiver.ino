// RECEIVER
#define LED_PIN 12
static const uint8_t DEVICE_ADDRESS = 2; // 0x02

byte messageArray[1];
uint8_t incomingAddress;
int diodeState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, diodeState);
}

void loop() {
  if (Serial.available()) {
    incomingAddress = Serial.read();
    if (incomingAddress == DEVICE_ADDRESS) {
      diodeState = !diodeState;
      digitalWrite(LED_PIN, diodeState);
    }
  }
}
