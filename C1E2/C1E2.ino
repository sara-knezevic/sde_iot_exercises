#include <TimerOne.h>

#define PIN_LED 13
#define PIN_BUTTON 2

int button_mode, previous_mode, led_mode;

void ISRFunction() { // Interrupt Service Routine
  led_mode = !led_mode;
  digitalWrite(PIN_LED, led_mode);
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), ISRFunction, FALLING);
  previous_mode = HIGH;
}

void loop() {
}
