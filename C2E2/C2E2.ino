#define PHOTO_IN A0
#define LED_GREEN 9

int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(PHOTO_IN);

  if (value > 512) {
    digitalWrite(LED_GREEN, LOW);
  } else {
    digitalWrite(LED_GREEN, HIGH);
  }
}
