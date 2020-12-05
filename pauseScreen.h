
#ifndef pauseScreen_h
#define pauseScreen_h

#include <SFML/Graphics.hpp>
#include "Screen.h"
#include <time.h>

class pauseScreen : public Screen 
{
private:
	bool pauseGame;
	bool exitGame;
public:
	/*************************************************************
	* Function: pauseScreen(constructor) -- Public
	* Description: Creates a constructor for a pauseScreen object that will
			  create a background sprite
	* Returns: n/a
	* Preconditions: Must be background that is at least 1024,768
				Must have a int input
	* Postconditions: a pauseScreen object is created
	*************************************************************/
	pauseScreen(int BGnum = 2) : Screen(BGnum) 
	{
		pauseGame = false;
		exitGame = false;
	}

	//Setter and Getter for pauseGame (bool)
	void setPause(bool inUse);
	bool checkIfPaused();


	//Setter and Getter for exitGame (bool)
	void setExit(bool inUse);
	bool checkIfExit();

	//Manages the Pause Screen
	bool pauseScreenGame(sf::RenderWindow& window);
};


#endif