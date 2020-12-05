#include "pauseScreen.h"

void pauseScreen::setPause(bool inUse)
{
	pauseGame = inUse;
}


bool pauseScreen::checkIfPaused()
{
	return pauseGame;

}

void pauseScreen::setExit(bool inUse)
{
	exitGame = inUse;
}


bool pauseScreen::checkIfExit()
{
	return exitGame;
}


bool pauseScreen::pauseScreenGame(sf::RenderWindow& window)
{
	
	if (!pauseGame)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pauseGame = true;
			int temp = time(NULL) + 1;

			while (temp > time(NULL));
		}
		else
		{
			pauseGame = false;
		}
	}
	else if (pauseGame)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pauseGame = false;
			int temp = time(NULL) + 1;

			while (temp > time(NULL));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			pauseGame = false;
			exitGame = true;
		}
		else
		{
			pauseGame = true;
		}

	}
	return pauseGame;
}