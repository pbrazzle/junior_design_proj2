#ifndef BOPITCONTROLLER
#define BOPITCONTROLLER

#include "BopItConsts.hpp"
#include "BopItGames.hpp"
#include "BopItSound.hpp"
#include "BopItScreen.hpp"

namespace BopItController
{
	namespace
	{
		int score = 0;
		
		bool playing = false;
		
		int chooseGame() { return random(3); }
		
		double getGameDelay() { return 1000; }
		
		bool chooseAndPlay()
		{
			using namespace BopItGames;
			
			double delay = getGameDelay();
			switch(chooseGame())
			{
				case DIG_IT:
					alertDigIt();
					return playDigIt(delay);
				case POP_IT:
					alertPopIt();
					return playPopIt(delay);
				case SHAKE_IT:
					alertShakeIt();
					return playShakeIt(delay);
			}
		}

		void reset()
		{
			BopItScreen::clearDisplay();
			score = 0;
			while (!playing);
		}
		
		void gameWon()
		{
			BopItScreen::gameWonDisplay();
			BopItSound::gameWonMusic();
			reset();
		}
		
		void gameLost()
		{
			BopItScreen::gameLostDisplay();
			BopItSound::gameLostMusic();
			reset();
		}
		
		void startButtonPressed()
		{
			playing = !playing;
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
		attachInterrupt(digitalPinToInterrupt(START_BUTTON), startButtonPressed, RISING);
		
		BopItIO::initializeSensors();
		BopItSound::initializeSpeaker();
		BopItScreen::initializeDisplay();
		
		while (!playing);
	}
	
	void gameStart()
	{
		BopItScreen::gameStartDisplay();
		BopItSound::gameStartMusic();
	}
	
	void playRound()
	{
		if (!playing) reset();
		if (!chooseAndPlay()) gameLost();
		score++;
		if (score == 99) gameWon();
	}
}

#endif
