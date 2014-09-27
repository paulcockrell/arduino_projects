#include <LiquidCrystal.h>
#include <LCDKeypad.h>

LCDKeypad lcd ;

#define COLUMNS 16
#define ROWS 2
#define SMILE_CHAR 1
#define CHEEKY_CHAR 2

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
  lcd.createChar(SMILE_CHAR, smile);
  lcd.createChar(CHEEKY_CHAR, cheeky);
}

void displaySpecialChar(int specialChar, int col, int row)
{
  lcd.setCursor(col, row);
  lcd.write(specialChar);  
  lcd.setCursor(0, 0); // put cursor back ready for next write
}

void bounceMessage(char* message, int specialChar)
{
  int counter;
  lcd.setCursor(16,0);

  lcd.clear();
  for (counter = COLUMNS; counter >= 0; counter--)
  {
    lcd.clear();
    lcd.setCursor(counter, 0);
    lcd.print(message);
    displaySpecialChar(specialChar, 8, 1);
    delay(200);
  }
  
  delay(500);
}

void setup()
{
  createSpecialChars();
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
  bounceMessage("Hi Mooma!", SMILE_CHAR);
  bounceMessage("Hi Poopa!", CHEEKY_CHAR);
}

