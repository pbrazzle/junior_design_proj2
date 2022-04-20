#include "BopItSound.hpp"

void setup()
{
  pinMode(SPEAKER, OUTPUT);
	BopItSound::initializeSpeaker();
}

void loop() 
{
	//Plays a tone for 500ms
	//BopItSound::playTone({131, 500});
  BopItSound::gameStartMusic();
  delay(100);
  BopItSound::gameWonMusic();
  delay(100);
  BopItSound::gameLostMusic();
  delay(100);
  BopItSound::gameOverMusic();
	delay(100);
}
