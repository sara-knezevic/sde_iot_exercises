#include <LiquidCrystal.h>

#define RS 12
#define EN 11

#define D4 7
#define D5 6
#define D6 5
#define D7 4

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("IoT!");
  lcd.setCursor(4, 1);
  lcd.print("Class 8");
}

void loop() {
  // put your main code here, to run repeatedly:

}
