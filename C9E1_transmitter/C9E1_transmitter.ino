// TRANSMITTER
static const uint8_t DEVICE_ADDRESS = 1; // 0x01

byte messageArray[1];

void setup() {
  Serial.begin(9600);
}

void loop() {
  messageArray[0] = 2; // 0x02 destination address
  Serial.write(messageArray, 1);
  delay(1000);
}
