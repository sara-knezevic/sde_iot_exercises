#include <Servo.h>

#define BUTTON_1 2
#define BUTTON_2 3
#define BUTTON_3 4
#define SERVO 9

Servo servObj;

int initPos = 0;
int button1Pos = 0;
int button2Pos = 90;
int button3Pos = 180;

int previousButton3_state = HIGH;
int button3_state = HIGH;

void ISRButton1() {
  servObj.write(button1Pos);
  delay(15);
}

void ISRButton2() {
  servObj.write(button2Pos);
  delay(15);
}

void setup() {
  servObj.attach(SERVO);

  pinMode(BUTTON_1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_1), ISRButton1, FALLING);
  pinMode(BUTTON_2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_2), ISRButton2, FALLING);
  pinMode(BUTTON_3, INPUT_PULLUP);
  servObj.write(initPos);
  delay(15);
}

void loop() {
  button3_state = digitalRead(BUTTON_3);

  if (button3_state == LOW && previousButton3_state == HIGH) { // falling edge without interrupts
    servObj.write(button3Pos);
    delay(15);
  }

  previousButton3_state = button3_state;
  delay(10);

  // main program

  
}
