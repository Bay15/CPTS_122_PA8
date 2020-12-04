#include "screen.h"
#include <iostream>

/*************************************************************
* Function: Screen(constructor) -- Public
* Description: Creates a constructor for a Screen object that will
			  create a background sprite
* Returns: n/a
* Preconditions: Must be background that is at least 1024,768
				Must have a int input
* Postconditions: a Screen object is created
*************************************************************/
Screen::Screen(int BGnum)
{
	if (!BGSet.loadFromFile("Resources/BGSet.png"))
	{
		//prints out to the terminal if a failure happened
		std::cout << "Failed to load Background Set" << std::endl;
	}

	background.setTexture(BGSet);
	setBG(BGnum);
}

/*************************************************************
* Function: setBG(int) -- Protected
* Description: Set the texture rectangle of the BG sprite to fit
				with the needed BG
* Returns: n/a
* Preconditions: Must be background that is at least 1024,768
				Must have a int input
* Postconditions: BG associated with specific number is displayed
*************************************************************/
void Screen::setBG(int BGnum)
{
	if (BGnum == 0) //main screen
	{
		background.setTextureRect(sf::IntRect(0, 0, 1024, 768));
	}

	else if (BGnum == 1) //how to screen
	{
		background.setTextureRect(sf::IntRect(1024, 0, 1024, 768));
	}

	else if (BGnum == 2) //pause screen
	{
		background.setTextureRect(sf::IntRect(1024 * 2, 0, 1024, 768));
	}

	else if (BGnum == 3) //win game screen
	{
		background.setTextureRect(sf::IntRect(0, 768, 1024, 768));
	}

	else //lose screen
	{
		background.setTextureRect(sf::IntRect(1024, 768, 1024, 768));
	}
}

/*************************************************************
* Function: Screen(sf::RenderWindow& ) -- Public (Virtual)
* Description: Draws the background in the window
* Returns: n/a
* Preconditions: Must be a texture attached to the sprite
* Postconditions: a background sprite is drawn
*************************************************************/
void Screen::makeBackground(sf::RenderWindow& window)
{
	window.draw(background);
}