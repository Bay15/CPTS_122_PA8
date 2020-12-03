#ifndef screen_h
#define screen_h

#include <SFML/Graphics.hpp>

class Screen
{
protected:
	sf::Sprite background;
	sf::Texture BGSet;
public:
	Screen(int BGnum)
	{
		BGSet.loadFromFile("Resources/BGSet.png");
		background.setTexture(BGSet);
		setBG(BGnum);
	}

	void setBG(int BGnum)
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
			background.setTextureRect(sf::IntRect(1024*2, 0, 1024, 768));
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

	void makeBackground(sf::RenderWindow& window)
	{
		window.draw(background);
	}

};


#endif 