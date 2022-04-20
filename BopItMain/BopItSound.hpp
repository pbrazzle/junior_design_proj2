#ifndef BOPITSOUND
#define BOPITSOUND

#include "BopItConsts.hpp"
#include "BopItScreen.hpp"

namespace BopItSound
{	
	struct note
	{
		int freq, time;
	};
	
	namespace
	{
		const int noteTime = 180;
    const int noteTimeLong = 250;
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
    const note C3l = {131, noteTimeLong};
    const note D3l = {147, noteTimeLong};
    const note E3l = {165, noteTimeLong};
    const note F3l = {175, noteTimeLong};
    const note G3l = {196, noteTimeLong};
    const note A3l = {220, noteTimeLong};
    const note B3l = {247, noteTimeLong};
    const note C4l = {262, noteTimeLong};
    const note D4l = {294, noteTimeLong};
    const note E4l = {330, noteTimeLong};
    const note F4l = {349, noteTimeLong};
    const note G4l = {392, noteTimeLong};
    const note A4l = {440, noteTimeLong};
    const note B4l = {494, noteTimeLong};
    const note C5l = {523, noteTimeLong};
    const note D5l = {587, noteTimeLong};
		
		const int gameOverLength = 5; 
		const note gameOverSong[gameOverLength] = {C4l, E3l, G3l, B3l, C4l};
		
		const int gameWonLength = 8;
		const note gameWonSong[gameWonLength] = {C3l, G3l, A3l, B3l, C4l, C4l, B3l, C4l};
		
		const int gameLostLength = 5; 
		const note gameLostSong[gameLostLength] = {C4l, B3l, A3l, G3l, C3l};
		
		const int gameStartLength = 15;
		const note gameStartSong[gameStartLength] = {A4l, F4l, D5l, C5l, C5l, A4l, F4l, F4l, D4l, G4l, G4l, G4l, G4l, G4l, G4l};
		
		const int digItLength = 5;
		const note digItSong[digItLength] = {C4, B3, C4, D4, C4};
		
		const int popItLength = 5;
		const note popItSong[popItLength] = {C4, E4, G4, E4, C4};
		
		const int shakeItLength = 5;
		const note shakeItSong[shakeItLength] = {C4, B3, C4, B3, C4};
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
		long int startTime = millis();
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
