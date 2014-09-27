#include <LiquidCrystal.h>


LiquidCrystal lcd(8,9,4,5,6,7);

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  delay(3000);

  lcd.clear();
  lcd.print("Hola Pablo!");

  delay(3000);

  lcd.clear();
  lcd.print("Hola Kimbo!");
}

