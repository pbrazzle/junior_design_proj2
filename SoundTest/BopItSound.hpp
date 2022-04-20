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
		const double noteTime = 200;
		const note C3 = {131, noteTime};
		const note D3 = {147, noteTime};
		const note E3 = {165, noteTime};
		const note F3 = {175, noteTime};
		const note G3 = {196, noteTime};
		const note A3 = {220, noteTime};
		const note B3 = {247, noteTime};
		const note C4 = {262, noteTime};
		const note D4 = {294, noteTime};
		const note E4 = {330, noteTime};
		const note F4 = {349, noteTime};
		const note G4 = {392, noteTime};
		const note A4 = {440, noteTime};
		const note B4 = {494, noteTime};
		const note C5 = {523, noteTime};
    const note D5 = {587, noteTime};
		
		const int gameOverLength = 5;
		const note gameOverSong[gameOverLength] = {C4, B3, A3, G3, C3};
		
		const int gameWonLength = 8;
		const note gameWonSong[gameWonLength] = {C3, G3, A3, B3, C4, C4, B3, C4};
		
		const int gameLostLength = 1;
		const note gameLostSong[gameLostLength] = {C4};
		
		const int gameStartLength = 15;
		const note gameStartSong[gameStartLength] = {A4, F4, D5, C5, C5, A4, F4, F4, D4, G4, G4, G4, G4, G4, G4};
		
		const int digItLength = 1;
		const note digItSong[digItLength] = {C4};
		
		const int popItLength = 1;
		const note popItSong[popItLength] = {C4};
		
		const int shakeItLength = 1;
		const note shakeItSong[shakeItLength] = {C4};
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
		while (millis() - startTime < n.time)
		{
			digitalWrite(SPEAKER, 0);
			delayMicroseconds(500000/n.freq);
			digitalWrite(SPEAKER, 1);
			delayMicroseconds(500000/n.freq);
		}			
		digitalWrite(SPEAKER, 0);
	}
	
	void gameOverMusic()
	{
		for (int i = 0; i < gameOverLength; i++) playTone(gameOverSong[i]);
	}
	
	void gameWonMusic()
	{
		for (int i = 0; i < gameWonLength; i++) playTone(gameWonSong[i]);
	}
	
	void gameLostMusic()
	{
		for (int i = 0; i < gameLostLength; i++) playTone(gameLostSong[i]);
	}
	
	void gameStartMusic()
	{
		for (int i = 0; i < gameStartLength; i++) playTone(gameStartSong[i]);
	}
	
	void digItMusic()
	{
		for (int i = 0; i < digItLength; i++) playTone(digItSong[i]);
	}
	
	void popItMusic()
	{
		for (int i = 0; i < popItLength; i++) playTone(popItSong[i]);
	}
	
	void shakeItMusic()
	{
		for (int i = 0; i < shakeItLength; i++) playTone(shakeItSong[i]);
	}
}
/*
ISR(TIMER2_OVF_vect){
    PORTD ^= (1<<SPEAKER); // toggle speaker pin
}
*/

#endif
