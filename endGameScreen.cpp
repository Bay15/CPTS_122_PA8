#include "endGameScreen.h"

/*************************************************************
* Function: mainScreen(sf::RenderWindow& ) -- Public
* Description: Uses the setBg function from parent class to choose write BG
				Draws the background in the window
* Returns: n/a
* Preconditions: Must be a texture attached to the sprite
* Postconditions: a background sprite is drawn
*************************************************************/
void endGameScreen::makeBackground(sf::RenderWindow& window, int BGnum)
{
	setBG(BGnum);
	window.draw(background);
}
