#include "BopItConsts.hpp"
#include "BopItIO.hpp"
#include "BopItScreen.hpp"
#include "BopItGames.hpp"
#include "BopItController.hpp"
#include "BopItSound.hpp"

void setup()
{
	BopItController::initialize();
	BopItController::gameStart();
}

void loop() 
{
	BopItController::playRound();
}
