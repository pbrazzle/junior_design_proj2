#include "BopItSound.hpp"

void setup()
{
	BopItSound::initializeSpeaker();
}

void loop() 
{
	//Plays a tone for 500ms
	BopItSound::playTone({440, 500});
	delay(500);
}