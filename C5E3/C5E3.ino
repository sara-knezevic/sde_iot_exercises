#define TEMP_IN A0
#define FAN 13

void setup() {
  Serial.begin(9600);
  pinMode(FAN, OUTPUT);
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

  if (temperature > 25.0) {
    digitalWrite(FAN, HIGH);
  } else {
    digitalWrite(FAN, LOW);
  }

  delay(2000);
}
