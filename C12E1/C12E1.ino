// receiver
#define LED_1 13
#define LED_2 12
#define LED_3 11

static const uint8_t DEVICE_ADDRESS = 0x01;
static const uint8_t PC_ID = 0x02;

byte messageArray[8];
uint8_t pinNumber = 13;
uint8_t pinNumberToSend = 13;

int diodeState = LOW;
uint8_t destination, source;
int pinNumberNew = 13;
uint8_t diodeStateNew;
float measurement = 26.7f;
int measurementInt = 26;

void setup() {
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  digitalWrite(LED_1, diodeState);
  digitalWrite(LED_2, diodeState);
  digitalWrite(LED_3, diodeState);
}

int analogValue;
float temp;

void loop() {
  
  if (Serial.available()) {
    destination = Serial.read();
    source = Serial.read();
    
    pinNumber = Serial.read();
    pinNumber = pinNumber << 8 | Serial.read();
    
    diodeStateNew = Serial.read();
    diodeStateNew = diodeStateNew << 8 | Serial.read();
    diodeStateNew = diodeStateNew << 16 | Serial.read();
    diodeStateNew = diodeStateNew << 24 | Serial.read();
    
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

  // 8 byte message
  // [1-byte][1-byte][2-bytes][4-bytes]
  // Header

  // sending floats!
  uint32_t *addr;
  float *addrF;
  analogValue = analogRead(A0);
  temp = (((float)analogValue/1023.0)*5000.0f)/10.0f;
  addr = (uint32_t *)&temp;
  
  messageArray[0] = PC_ID;
  messageArray[1] = DEVICE_ADDRESS;
  // Payload
  messageArray[2] = (int8_t)(pinNumberNew & 0xFF);
  messageArray[3] = (int8_t)(pinNumberNew >> 8) & 0xFF;
  // uint 33 -> 0x00 0x00 0x00 0x21
  // & 0xFF keeps only last position, the rest become zeroes
  messageArray[4] = (int8_t)(*addr & 0xFF); // use *addr instead of measurementInt to send floats
  messageArray[5] = (int8_t)(*addr >> 8) & 0xFF; // >> shift 8 bits
  messageArray[6] = (int8_t)(*addr >> 16) & 0xFF; // >> shift 16 bits
  messageArray[7] = (uint8_t)(*addr >> 24) & 0xFF; // >> shift 24


  Serial.write(messageArray, 8);
  delay(1000);
}
