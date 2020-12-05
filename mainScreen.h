
#ifndef mainScreen_h
#define mainScreen_h

#include <SFML/Graphics.hpp>
#include "screen.h"

class mainScreen : public Screen
{
private:
	sf::Texture buttonSet;
	sf::Sprite startButton;
	sf::Sprite howToButton;
	sf::Sprite exitButton;

	//Bools to know whether these are happening or not
	bool startGame;
	bool howToPage;
public:
	/*************************************************************
	* Function: mainScreen(constructor) -- Public
	* Description: Creates a constructor for a mainScreen object that will
			  create a background sprite
	* Returns: n/a
	* Preconditions: Must be background that is at least 1024,768
				Must have a int input
	* Postconditions: a mainScreen object is created
	*************************************************************/
	mainScreen(int BGnum = 0) : Screen(BGnum)
	{
		buttonSet.loadFromFile("Resources/ButtonSet.png");

		startButton.setTexture(buttonSet);
		startButton.setTextureRect(sf::IntRect(0, 0, 384, 64));
		startButton.setPosition(320, 512);

		howToButton.setTexture(buttonSet);
		howToButton.setTextureRect(sf::IntRect(0, 64, 384, 64));
		howToButton.setPosition(320, 580);

		exitButton.setTexture(buttonSet);
		exitButton.setTextureRect(sf::IntRect(0, 128, 384, 64));
		exitButton.setPosition(320, 648);

		startGame = false;
		howToPage = false;
	}


	void makeActive(sf::RenderWindow& window);

	void makeBackground(sf::RenderWindow& window, int BGnum);

	void makeMainScreen(sf::RenderWindow& window);

	bool checkIfStart(sf::RenderWindow& window);

	void setStart(bool inUse);

	bool checkIfHowTo(sf::RenderWindow& window);

	void setHowTo(bool inUse);

	bool checkIfExit(sf::RenderWindow& window);

};

#endif // !"mainScreen_h"
