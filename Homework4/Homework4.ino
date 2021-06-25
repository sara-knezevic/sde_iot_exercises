#include <LiquidCrystal.h>

#define RS 12
#define EN 10

#define D4 7
#define D5 6
#define D6 5
#define D7 4

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
String message = "";

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 4);
}

void loop() {
  delay(10);
  
  if (Serial.available()) {
    message = Serial.readString();
    lcd.print(message);
    delay(2000);
    lcd.clear();
  }
}
