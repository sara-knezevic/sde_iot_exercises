#include <TimerOne.h>

#define PIN_LED 13

int led_mode = HIGH;

void ISRFunction() {
  digitalWrite(PIN_LED, led_mode);
  // delay(500);
  led_mode = !led_mode;
}

void setup() {
  pinMode(PIN_LED, OUTPUT); // input/output
  Timer1.initialize(1000000); // microseconds
  Timer1.attachInterrupt(ISRFunction);
}

void loop() {}
