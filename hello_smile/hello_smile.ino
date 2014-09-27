#include <LiquidCrystal.h>
#include <LCDKeypad.h>

LiquidCrystal lcd(8,9,4,5,6,7);
LCDKeypad keypad;

byte smile[8] = {
  B00000,
  B01010,
  B00000,
  B00100,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte cheeky[8] = {
  B00000,
  B11010,
  B00000,
  B00100,
  B00000,
  B10001,
  B01110,
  B00100,
};

void createSpecialChars()
{
  lcd.createChar(1,smile);
  lcd.createChar(2,cheeky);
}

void setup()
{
  createSpecialChars();
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  delay(3000);

  lcd.clear();
  lcd.print("Hi Mooma ");
  lcd.setCursor(8,1);
  lcd.write(1);

  delay(3000);

  lcd.clear();
  lcd.print("Hi Poopa ");
  lcd.setCursor(8,1);
  lcd.write(2);
}

