#ifndef BOPITSOUND
#define BOPITSOUND

#include "BopItConsts.hpp"

namespace BopItSound
{	
	struct note
	{
		double freq, time;
	};
	
	namespace
	{
		const note C3 = {131, 0.2};
		const note D3 = {147, 0.2};
		const note E3 = {165, 0.2};
		const note F3 = {175, 0.2};
		const note G3 = {196, 0.2};
		const note A3 = {220, 0.2};
		const note B3 = {247, 0.2};
		const note C4 = {262, 0.2};
		const note D4 = {294, 0.2};
		const note E4 = {330, 0.2};
		const note F4 = {349, 0.2};
		const note G4 = {392, 0.2};
		const note A4 = {440, 0.2};
		const note B4 = {494, 0.2};
		const note C5 = {523, 0.2};
		
		const int gameOverLength = 5;
		const note gameOverSong[gameOverLength] = {C4, B3, A3, G3, C3};
	}
	
	void initializeSpeaker()
	{
		/*
		TCCR2A = 0x00; 								// Wave Form Generation Mode 0: Normal Mode; OC2A disconnected
		TCCR2B = (1<<CS22) + (1<<CS21) + (1<<CS20); // prescaler = 1024
		TIMSK2 = 0; 								// interrupt when TCNT2 is overflowed
		*/
	}
	
	void playTone(const note n)
	{
		int startTime = millis();
		while (millis() - startTime < n.time*1000)
		{
			digitalWrite(SPEAKER, 0);
			delay(1000/n.freq);
			digitalWrite(SPEAKER, 1);
			delay(1000/n.freq);
		}			
		digitalWrite(SPEAKER, 0);
	}
	
	void gameOverMusic()
	{
		for (int i = 0; i < gameOverLength; i++) playTone(gameOverSong[i]);
	}
	
	void gameWonMusic()
	{
		
	}
	
	void gameLostMusic()
	{
		
	}
	
	void gameStartMusic()
	{
		
	}
	
	void digItMusic()
	{
		
	}
	
	void popItMusic()
	{
		
	}
	
	void shakeItMusic()
	{
		
	}
}
/*
ISR(TIMER2_OVF_vect){
    PORTD ^= (1<<SPEAKER); // toggle speaker pin
}
*/

#endif
