
#ifndef pauseScreen_h
#define pauseScreen_h

#include <SFML/Graphics.hpp>
#include "mainScreen.h"

class pauseScreen : public mainScreen 
{
private:
	bool pauseGame;
	bool exitGame;
public:
	pauseScreen(int BGnum = 2) : mainScreen(BGnum) 
	{
		pauseGame = false;
		exitGame = false;
	}

	void setPause(bool inUse)
	{
		pauseGame = inUse;
	}
	void setExit(bool inUse)
	{
		exitGame = inUse;
	}

	bool checkIfPaused()
	{
		return pauseGame;
		
	}

	bool checkIfExit()
	{
		return exitGame;
	}
	void makePauseScreen(sf::RenderWindow& window)
	{
		mainScreen::setBG(2);
		mainScreen::makeBackground(window);
	}

	bool pauseScreenGame(sf::RenderWindow& window)
	{
		if (!pauseGame && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			pauseGame = true;
			exitGame = false;
			return pauseGame;
		}
		else if (pauseGame)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				pauseGame = false;
				exitGame = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				pauseGame = false;
				exitGame = true;
			}
			else
			{
				return pauseGame;
			}
		}
		else
		{
			pauseGame = false;
			exitGame = false;
		}
		return pauseGame;
	}
};


#endif