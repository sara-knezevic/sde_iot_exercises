// receiver
#define LED_1 13
#define LED_2 12
#define LED_3 11

static const uint8_t DEVICE_ADDRESS = 0x01;
static const uint8_t PC_ID = 0x02;

byte messageArray[4];
uint8_t pinNumber = 13;
uint8_t pinNumberToSend = 13;

int diodeState = LOW;
uint8_t destination, source;
int pinNumberNew = 13;
uint8_t diodeStateNew;
float measurement = 26.7f;

void setup() {
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_1, diodeState);
  digitalWrite(LED_2, diodeState);
  digitalWrite(LED_3, diodeState);
}

void loop() {
  if (Serial.available()) {
    destination = Serial.read();
    source = Serial.read();
    pinNumber = Serial.read();
    diodeStateNew = Serial.read();
    
    diodeState = (int)diodeStateNew;
    pinNumberNew = (int)pinNumber;

    if (destination == DEVICE_ADDRESS) {
      digitalWrite(pinNumberNew, diodeState);
    }
    pinNumberToSend--;
  }

  if (pinNumberToSend < 11) {
    pinNumberToSend = 13;
  }

  messageArray[0] = PC_ID;
  messageArray[1] = DEVICE_ADDRESS;
  messageArray[2] = (uint8_t)pinNumberToSend;
  messageArray[3] = (int8_t)diodeState;

  Serial.write(messageArray, 4);
  delay(1000);
}
