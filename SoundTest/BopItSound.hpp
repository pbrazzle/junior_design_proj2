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
		const note A4 = {440, 0.2};
		
		const int gameOverLength = 1;
		const note gameOverSong[gameOverLength] = {A4};
	}
	
	void initializeSpeaker()
	{
		TCCR2A = 0x00; 								// Wave Form Generation Mode 0: Normal Mode; OC2A disconnected
		TCCR2B = (1<<CS22) + (1<<CS21) + (1<<CS20); // prescaler = 1024
		TIMSK2 = 0; 								// interrupt when TCNT2 is overflowed
	}
	
	void playTone(const note n)
	{
		//Turn on speaker
		TIMSK2 = (1<<TOIE2);	
		
		//Set frequency
		
		delay(n.time);
		
		//Turn off speaker
		TIMSK2 = 0;				
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

ISR(TIMER2_OVF_vect){
    PORTD ^= (1<<SPEAKER); // toggle speaker pin
}

#endif
