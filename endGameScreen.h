#ifndef endGameScreen_h
#define endGameScreen_h

#include <SFML/Graphics.hpp>
#include "screen.h"

class endGameScreen : public Screen
{
public:
	/*************************************************************
	* Function: endGameScreen(constructor) -- Public
	* Description: Creates a constructor for a endGameScreen object that will
			  create a background sprite
	* Returns: n/a
	* Preconditions: Must be background that is at least 1024,768
				Must have a int input
	* Postconditions: a endGameScreen object is created
	*************************************************************/
	endGameScreen(int BGnum = 4) : Screen(BGnum)
	{
		
	}

	void makeBackground(sf::RenderWindow& window, int BGnum);

	bool checkIfEnd(sf::RenderWindow& window, bool Alive, bool Won) //checks if the game has ended
	{
		if (Won) //if the player won
		{
			makeBackground(window, 3); //make winning screen
			return true;
		}
		if (!Alive) //if the player died
		{
			makeBackground(window, 4); //make loss screen
			return true;
		}
		else //if not return false
		{
			return false;
		}

	}

};


#endif 
