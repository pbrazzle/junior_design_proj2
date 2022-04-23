#ifndef BOPITCONTROLLER
#define BOPITCONTROLLER

#include "BopItConsts.hpp"
#include "BopItGames.hpp"
#include "BopItSound.hpp"
#include "BopItScreen.hpp"

namespace BopItController
{
  void gameStart()
  {
    //Wait for start button
    while (!digitalRead(START_BUTTON));
    BopItScreen::gameStartDisplay();
    BopItSound::gameStartMusic();
  }
  
	namespace
	{
		int score = 0;
		
		int chooseGame() { return random(3); }
		
		double getGameDelay() { return 2000 - 10*score; }
		
		bool chooseAndPlay()
		{
			using namespace BopItGames;
			
			double delay = getGameDelay();
			switch(chooseGame())
			{
				case DIG_IT:
					alertDigIt();
          BopItScreen::writeToDisplay("Score: " + String(score));
					return playDigIt(delay);
				case POP_IT:
					alertPopIt();
          BopItScreen::writeToDisplay("Score: " + String(score));
					return playPopIt(delay);
				case SHAKE_IT:
					alertShakeIt();
          BopItScreen::writeToDisplay("Score: " + String(score));
					return playShakeIt(delay);
			}
      return false;
		}

		void reset()
		{
			BopItScreen::clearDisplay();
      BopItSound::gameOverMusic();
			delay(1000);
			score = 0;
      gameStart();
			//while (!playing);
		}
		
		void gameWon()
		{
			BopItScreen::gameWonDisplay();
			BopItSound::gameWonMusic();
      delay(500);
			reset();
		}
		
		void gameLost()
		{
			BopItScreen::gameLostDisplay();
			BopItSound::gameLostMusic();
      delay(500);
			reset();
		}
	}
	
	void initialize()
	{
		randomSeed(analogRead(0));
		
		score = 0;
		
		pinMode(START_BUTTON, INPUT);
		pinMode(POP_BUTTON, INPUT);
		pinMode(DIG_BUTTON, INPUT);
		pinMode(SPEAKER, OUTPUT);
	
		BopItIO::initializeSensors();
		BopItSound::initializeSpeaker();
		BopItScreen::initializeDisplay();
	}
	
	void playRound()
	{
		//if (!playing) reset();
		if (!chooseAndPlay()) gameLost();
		score++;
		if (score == 99) gameWon();
    BopItScreen::clearDisplay();
	}
}

#endif
