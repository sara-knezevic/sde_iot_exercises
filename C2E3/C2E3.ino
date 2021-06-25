#define PHOTO_IN A0
#define LED_GREEN 9

int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = 255 - map(analogRead(PHOTO_IN), 0, 1023, 0, 255);
  analogWrite(LED_GREEN, value); // 0 - 255; 0 == 0V; 255 == 5V;
}
