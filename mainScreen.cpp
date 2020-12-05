#include "mainScreen.h"


/*************************************************************
* Function: makeActive(sf::RenderWindow& ) -- Public
* Description: Checks where the mouse cursor is and changes to active version 
				of the button sprite if the cursor is over it
* Returns: n/a
* Preconditions: In order to see the buttons, they must have been drawn
* Postconditions: Changes texture according to whether a mouse cursor is or isn't over it
*************************************************************/
void mainScreen::makeActive(sf::RenderWindow& window)
{
	//if mouse button is within the start button sprite
	if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) 
	{
		startButton.setTextureRect(sf::IntRect(384, 0, 384, 64)); //sets to active texture
	}
	else //mouse button is not in the start button sprite
	{
		startButton.setTextureRect(sf::IntRect(0, 0, 384, 64)); //sets to inactive texture
	}

	//if mouse button is within the howTo button sprite
	if (howToButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
	{
		howToButton.setTextureRect(sf::IntRect(384, 64, 384, 64)); //set to active texture
	}
	else //mouse button is not in the howTo button sprite
	{
		howToButton.setTextureRect(sf::IntRect(0, 64, 384, 64)); //set to inactive texture
	}

	//if mouse is within the exit button sprite
	if (exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
	{
		exitButton.setTextureRect(sf::IntRect(384, 128, 384, 64)); //sets to active texture
	}
	else //mouse is not within the exit button sprite
	{
		exitButton.setTextureRect(sf::IntRect(0, 128, 384, 64)); //sets to inactive texture
	}
}

/*************************************************************
* Function: mainScreen(sf::RenderWindow& ) -- Public 
* Description: Uses the setBg function from parent class to choose write BG
				Draws the background in the window
* Returns: n/a
* Preconditions: Must be a texture attached to the sprite
* Postconditions: a background sprite is drawn
*************************************************************/
void mainScreen::makeBackground(sf::RenderWindow& window, int BGnum)
{
	setBG(BGnum);
	window.draw(background);
}


/*************************************************************
* Function: makeMainScreen(sf::RenderWindow& ) -- Public
* Description: Draws all of the components for the mainScreen
* Returns: n/a
* Preconditions: Must be a texture attached to all the sprites 
* Postconditions: a mainScreen is drawn
*************************************************************/
void mainScreen::makeMainScreen(sf::RenderWindow& window) //draws the mainscreen to the window
{
	makeBackground(window, 0);
	window.draw(startButton);
	window.draw(howToButton);
	window.draw(exitButton);
}

bool mainScreen::checkIfStart(sf::RenderWindow& window) //check to see if the start button is pressed
{
	if (!startGame && !howToPage)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				startGame = true;
			}
			else
			{
				return false;
			}
		}
	}
	return startGame;
}

void mainScreen::setStart(bool inUse)
{
	startGame = inUse;
}

bool mainScreen::checkIfHowTo(sf::RenderWindow& window)
{
	if (!startGame && !howToPage)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (howToButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				howToPage = true;
			}
			else
			{
				howToPage = false;
			}
		}
	}
	return howToPage;
}

void mainScreen::setHowTo(bool inUse)
{
	howToPage = inUse;
}

bool mainScreen::checkIfExit(sf::RenderWindow& window)
{
	if (!startGame && !howToPage)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				return true;
			}
		}
	}
	return false;
}
