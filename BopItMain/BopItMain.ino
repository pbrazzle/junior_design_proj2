#include "BopItConsts.hpp"
#include "BopItIO.hpp"
#include "BopItScreen.hpp"
#include "BopItGames.hpp"
#include "BopItController.hpp"
#include "BopItSound.hpp"

/*
	TODO:
		Controller - Add power button functionality
		Games - Win conditions for shake it
		Sound - Write songs
		Display - Write display strings
		Consts - Set GPIO pins
		Sound - Test speaker
*/

void setup()
{
	BopItController::initialize();
	BopItController::gameStart();
}

void loop() 
{
	BopItController::playRound();
}
