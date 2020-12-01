
#ifndef mainScreen_h
#define mainScreen_h

#include <SFML/Graphics.hpp>
#include <iostream>

class mainScreen
{
private:
	sf::Texture buttonSet;
	bool startGame;
public:
	sf::Text title;
	sf::Sprite startButton;
	sf::Sprite howToButton;
	sf::Sprite exitButton;
	

	mainScreen()
	{
		/*title.setString("Maze Game Xtreme");
		title.setCharacterSize(128);
		title.setPosition(320, 128);
		title.setFillColor(sf::Color::Red);*/

		buttonSet.loadFromFile("Resources/ButtonSet.png");

		startButton.setTexture(buttonSet);
		startButton.setTextureRect(sf::IntRect(0, 0, 384, 64));
		startButton.setPosition(320,512);

		howToButton.setTexture(buttonSet);
		howToButton.setTextureRect(sf::IntRect(0, 64, 384, 64));
		howToButton.setPosition(320, 580);

		exitButton.setTexture(buttonSet);
		exitButton.setTextureRect(sf::IntRect(0, 128, 384, 64));
		exitButton.setPosition(320, 648);

		startGame = false;
	}

	bool checkIfStart(sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				startGame = true;
			}
		}
		return startGame;
	}

	bool checkIfHowTo(sf::RenderWindow &window)
	{
	}

	bool checkIfExit(sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				return true;
			}
		}
	}

};

#endif // !"mainScreen_h"
