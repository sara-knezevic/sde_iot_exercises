#define ANALOG_IN A0

int value = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(ANALOG_IN);
  Serial.println(value);
}
