#include "pauseScreen.h"

void pauseScreen::setPause(bool inUse) //establishes if the puase menu is up as  true or false
{
	pauseGame = inUse;
}


bool pauseScreen::checkIfPaused() //returns true if the puase menu is up
{
	return pauseGame;

}

void pauseScreen::setExit(bool inUse) //establishes if the game was exited as true or false
{
	exitGame = inUse;
}


bool pauseScreen::checkIfExit() //returns true if the game has been exited
{
	return exitGame;
}


bool pauseScreen::pauseScreenGame(sf::RenderWindow& window) //puases the game
{
	
	if (!pauseGame) //if the game is not already paused
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //if the escape key is pressed
		{
			pauseGame = true; //pause the game
			int temp = time(NULL) + 1;

			while (temp > time(NULL));
		}
		else
		{
			pauseGame = false; //otherwise don't
		}
	}
	else if (pauseGame) //if the game is already paused
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) //if the escape key is pressed
		{
			pauseGame = false; //unpause the game
			int temp = time(NULL) + 1;

			while (temp > time(NULL));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //if the enter key is pressed
		{
			pauseGame = false; //unpause the game and exit 
			exitGame = true;
		}
		else //otherwise pause game remains true
		{
			pauseGame = true; 
		}

	}
	return pauseGame;
}
