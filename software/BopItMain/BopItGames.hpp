#ifndef BOPITGAMES
#define BOPITGAMES

#include "BopItSound.hpp"
#include "BopItScreen.hpp"
#include "BopItIO.hpp"

namespace BopItGames
{	
	void alertDigIt()
	{
		BopItScreen::digItDisplay();
		BopItSound::digItMusic();
	}
	
	bool playDigIt(double delay)
	{
    unsigned long currentTime = millis();
    
    while (millis() - currentTime < delay)
    {
      if (BopItIO::readDigButton()) return true;
    }
    return false;
	}
	
	void alertPopIt()
	{
		BopItScreen::popItDisplay();
		BopItSound::popItMusic();
	}
	
	bool playPopIt(double delay)
	{
    unsigned long currentTime = millis();
    
    while (millis() - currentTime < delay)
    {
      if (BopItIO::readPopButton()) return true;
    }
    return false;
	}
	
	void alertShakeIt()
	{
		BopItScreen::shakeItDisplay();
		BopItSound::shakeItMusic();
	}
	
	bool playShakeIt(double delay)
	{
		unsigned long currentTime = millis();
		
		while (millis() - currentTime < delay)
		{
			BopItIO::accelData data = BopItIO::readShakeSensor();
      if (data.accelX&0x8000 && data.accelY&0x8000) return true;
		}
		
		return false;
	}
}

#endif
