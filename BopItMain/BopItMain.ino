#include "BopItConsts.hpp"
#include "BopItIO.hpp"
#include "BopItScreen.hpp"
#include "BopItGames.hpp"
#include "BopItController.hpp"
#include "BopItSound.hpp"

/*
	TODO:
		Games - Win conditions for shake it
		Sound - Write songs
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
