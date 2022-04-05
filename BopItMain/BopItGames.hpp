#ifndef BOPITGAMES
#define BOPITGAMES

#include "BopItSound.hpp"
#include "BopItScreen.hpp"

namespace BopItGames
{
	namespace
	{
		bool waitForButton(int pin, double delay)
		{
			unsigned long currentTime = millis();
			
			while (millis() - currentTime < delay)
			{
				if (digitalRead(pin)) return true;
			}
			return false;
		}
	}
	
	void alertDigIt()
	{
		BopItScreen::digItDisplay();
		BopItSound::digItMusic();
	}
	
	bool playDigIt(double delay)
	{
		return waitForButton(DIG_BUTTON, delay);
	}
	
	void alertPopIt()
	{
		BopItScreen::popItDisplay();
		BopItSound::popItMusic();
	}
	
	bool playPopIt(double delay)
	{
		return waitForButton(POP_BUTTON, delay);
	}
	
	void alertShakeIt()
	{
		BopItScreen::shakeItDisplay();
		BopItSound::shakeItMusic();
	}
	
	bool playShakeIt(double delay)
	{
		return false;
	}
}

#endif
