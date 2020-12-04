#ifndef screen_h
#define screen_h

#include <SFML/Graphics.hpp>

class Screen
{
protected:
	sf::Sprite background;
	sf::Texture BGSet;

	//Functions to choose correct BG
	void setBG(int BGnum);
public:
	//Constructor
	Screen(int BGnum);

	//Draws the background in given window
	virtual void makeBackground(sf::RenderWindow& window);
};


#endif 