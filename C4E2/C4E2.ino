#define VIBRATION 13
#define TOUCH 12
#define SOUND 11
#define PIR 10
#define INFRARED 9

void setup() {
  Serial.begin(9600);
  
  pinMode(VIBRATION, INPUT);
  pinMode(TOUCH, INPUT);
  pinMode(SOUND, INPUT);
  pinMode(PIR, INPUT);
  pinMode(INFRARED, INPUT);
}

void loop() {
  if (digitalRead(VIBRATION)) {
    Serial.println("Vibration detected!");
  }
  if (digitalRead(TOUCH)) {
    Serial.println("Touch detected!");
  }
  if (digitalRead(SOUND)) {
    Serial.println("Sound detected!");
  }
  if (digitalRead(PIR)) {
    Serial.println("Movement detected!");
  }
  if (digitalRead(INFRARED)) {
    Serial.println("Obstacle detected!");
  }
}
