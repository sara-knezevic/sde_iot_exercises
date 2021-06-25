// TRANSMITTER
static const uint8_t DEVICE_ADDRESS = 1; // 0x01

byte messageArray[3];
uint8_t pinNumber = 13;

void setup() {
  Serial.begin(9600);
}

void loop() {
  messageArray[0] = 2; // 0x02 destination address
  messageArray[1] = DEVICE_ADDRESS; // 0x01 source address
  messageArray[2] = pinNumber--; // 0x0D - pin number to change
  Serial.write(messageArray, 3);
  delay(1000);
  if (pinNumber < 11) {
    pinNumber = 13;
  }
}
