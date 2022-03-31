#ifndef BOPITGAMES
#define BOPITGAMES

#include "BopItSound.hpp"
#include "BopItScreen.hpp"

namespace BopItGames
{
	void alertDigIt()
	{
		BopItScreen::digItDisplay();
		BopItSound::digItMusic();
	}
	
	bool playDigIt(double delay)
	{
		return false;
	}
	
	void alertPopIt()
	{
		BopItScreen::popItDisplay();
		BopItSound::popItMusic();
	}
	
	bool playPopIt(double delay)
	{
		return false;
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
