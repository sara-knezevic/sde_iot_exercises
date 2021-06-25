#define ECHO 12
#define TRIGGER 13

long duration, distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
}

long calculateDistance() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);

//  distance = (duration * 0.034) / 2;
  distance = duration / 29 / 2;

  return distance;
}

void loop() {
  Serial.print("Distance: ");
  Serial.println(calculateDistance());
  delay(500);
}
