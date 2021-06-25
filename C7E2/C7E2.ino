#include <Servo.h>

#define SERVO 9
Servo servObj;
int analogPot = 0;

void setup() {
  servObj.attach(SERVO);
}

void loop() {
  analogPot = analogRead(A0);
  analogPot = map(analogPot, 0, 1023, 0, 180);

  servObj.write(analogPot);
  delay(50);
}
