// RECEIVER
#define LED_PIN_1 13
#define LED_PIN_2 12
#define LED_PIN_3 11
static const uint8_t DEVICE_ADDRESS = 2; // 0x02

uint8_t sourceAddress, destinationAddress, pinNumber;
int diodeState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  digitalWrite(LED_PIN_1, diodeState);
  digitalWrite(LED_PIN_2, diodeState);
  digitalWrite(LED_PIN_3, diodeState);
}

void loop() {
  if (Serial.available()) {
    destinationAddress = Serial.read();
    sourceAddress = Serial.read();
    pinNumber = Serial.read();
    if (destinationAddress == DEVICE_ADDRESS) {
      diodeState = !diodeState;
      digitalWrite(pinNumber, diodeState);
    }
  }
}
