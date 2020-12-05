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

	bool checkIfEnd(sf::RenderWindow& window, bool Alive, bool Won)
	{
		if (Won)
		{
			makeBackground(window, 3);
			return true;
		}
		if (!Alive)
		{
			makeBackground(window, 4);
			return true;
		}
		else
		{
			return false;
		}

	}

};


#endif 
