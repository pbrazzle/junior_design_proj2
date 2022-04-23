#ifndef BOPITSCREEN
#define BOPITSCREEN

//Using Sunfounder LCD 1602 which works with the LiquidCrystal.h Arduino library
#include <LiquidCrystal_I2C.h>

namespace BopItScreen
{
	namespace
	{
		LiquidCrystal_I2C lcd(0x27,20,4);
	}

 void writeToDisplay(String s)
 {
   lcd.setCursor(1,0);
   lcd.print(s);
 }
	
	void initializeDisplay()
	{
		lcd.init();
		lcd.backlight();
	}

  void clearDisplay()
  {
    lcd.clear();
  }
  
	void gameWonDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Wow!");
		lcd.setCursor(1,1);
		lcd.print("You win!");
	}
	
	void gameLostDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Aww!");
		lcd.setCursor(1,1);
		lcd.print("You lost!");
	}
	
	void gameStartDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Yo!");
		lcd.setCursor(1,1);
		lcd.print("Let's play!");
	}
	
	void digItDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Yo!");
		lcd.setCursor(1,1);
		lcd.print("Dig It!");
	}
	
	void popItDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Yo!");
		lcd.setCursor(1,1);
		lcd.print("Pop It!");
	}

	void shakeItDisplay()
	{
		clearDisplay();
		lcd.setCursor(1,0);
		lcd.print("Yo!");
		lcd.setCursor(1,1);
		lcd.print("Shake It!");
	}	
}

#endif
