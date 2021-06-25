#define PIN_DIODE_13 13
#define PIN_DIODE_12 12
#define PIN_DIODE_11 11

String msg = "";

void setup() {
  Serial.begin(9600);
  pinMode(PIN_DIODE_11,OUTPUT);
  pinMode(PIN_DIODE_12,OUTPUT);
  pinMode(PIN_DIODE_13,OUTPUT);
}

bool setValue(int pin, String msg) {
  if (msg.length() > 0) {
    if (msg == "on") {
      digitalWrite(pin, HIGH);
    } else {
      digitalWrite(pin, LOW);
    }
    msg = "";
    return true;
  }
  return false;
}

void loop() {

  String pinNumStr, delimeter, value;
  
  delay(10);

  // example : 13-on/off-&&-\r\n
  if (Serial.available()) {
    pinNumStr = Serial.readStringUntil('-');
    value = Serial.readStringUntil('-');
    delimeter = Serial.readStringUntil('-');
  }

    int pinNum = pinNumStr.toInt();
    switch (pinNum) {
      case PIN_DIODE_11: {
        setValue(pinNum, value);
        break;
      }
      case PIN_DIODE_12: {
        setValue(pinNum, value);
        break;
      }
      case PIN_DIODE_13: {
        setValue(pinNum, value);
        break;
      }
    }
}
