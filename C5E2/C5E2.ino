#define TEMP_IN A0

void setup() {
  Serial.begin(9600);
}

int vIn = 0;
double mvIn = 0;
double temperature = 0;

void loop() {
  // 1C is 0.001V
  vIn = analogRead(TEMP_IN);
  mvIn = (vIn/1023.0) * 5000;
  Serial.print("Milivolts: ");
  Serial.println(mvIn);
  temperature = mvIn / 10;
  Serial.println(temperature);

  delay(2000);
}
