#include <LiquidCrystal.h>
#include <LCDKeypad.h>

#define RIGHT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define SELECT 4

LCDKeypad lcd;

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Press a button..");
  lcd.setCursor(0,1);
  lcd.print("$>"); 
}

void loop()
{
  int button;
  button = waitButton();
  displayButtonPress(button);
  delay(1000);
  setup();
}

void displayButtonPress(int button)
{
  char* button_name;
  switch(button)
  {
  case RIGHT:
    button_name = "right";
    break;
  case UP:
    button_name = "up";
    break;
  case DOWN:
    button_name = "down";
    break;
  case LEFT:
    button_name = "left";
    break;
  case SELECT:
    button_name = "select";
    break;
  default:
    button_name = "unknown btn";
    break;
  }
  
  char buf[16];
  sprintf(buf, "$> %d ", button);
  strncat(buf, button_name, 11); 
  lcd.setCursor(0,1);
  lcd.print(buf);
  delay(1000);
}

int waitButton()
{
  int buttonPressed; 

  waitReleaseButton;
  lcd.blink();

  while((buttonPressed=lcd.button())==KEYPAD_NONE)
  {
  }
  
  delay(50);  
  lcd.noBlink();

  return buttonPressed;
}

void waitReleaseButton()
{
  delay(50);

  while(lcd.button()!=KEYPAD_NONE)
  {
  }

  delay(50);
}

