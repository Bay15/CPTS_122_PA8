
#ifndef mainScreen_h
#define mainScreen_h

#include <SFML/Graphics.hpp>
#include <iostream>

class mainScreen
{
private:
	sf::Texture buttonSet;
	bool startGame;
	bool howToPage;
public:
	sf::Sprite backgroundMain;
	sf::Sprite startButton;
	sf::Sprite howToButton;
	sf::Sprite exitButton;
	

	mainScreen()
	{
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

	void makeActive(sf::RenderWindow& window)
	{
		if (startButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			startButton.setTextureRect(sf::IntRect(384, 0, 384, 64));
		}
		else
		{
			startButton.setTextureRect(sf::IntRect(0, 0, 384, 64));
		}
		if (howToButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			howToButton.setTextureRect(sf::IntRect(384, 64, 384, 64));
		}
		else
		{
			howToButton.setTextureRect(sf::IntRect(0, 64, 384, 64));
		}
		if (exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		{
			exitButton.setTextureRect(sf::IntRect(384, 128, 384, 64));
		}
		else
		{
			exitButton.setTextureRect(sf::IntRect(0, 128, 384, 64));
		}
	}

	void makeMainScreen(sf::RenderWindow& window)
	{
		window.draw(startButton);
		window.draw(howToButton);
		window.draw(exitButton);
	}

	bool checkIfStart(sf::RenderWindow& window)
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
		return startGame;
	}

	void setStart(bool inUse)
	{
		startGame = inUse;
	}

	bool checkIfHowTo(sf::RenderWindow &window)
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
		return howToPage;
	}

	void setHowTo(bool inUse)
	{
		howToPage = inUse;
	}

	bool checkIfExit(sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (exitButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

};

#endif // !"mainScreen_h"
