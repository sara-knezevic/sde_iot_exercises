#define PHOTORES A0
#define LED_RED 9
#define LED_YELLOW 8
#define LED_GREEN 7

void setup() {
  pinMode(PHOTORES, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

int brightness;

void loop() {
  brightness = analogRead(PHOTORES);

  if (brightness < 341) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
  } else if (brightness > 682) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, HIGH);
  } else {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
  }
}
