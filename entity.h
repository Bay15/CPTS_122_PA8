#ifndef entity_h
#define entity_h

#include <SFML/Graphics.hpp>

class Entity
{
private:
	int LENGTH;
	int WIDTH;
	int X;
	int Y;

public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Text text;

	Entity()
	{}

	//draw
};

#endif // !entity_h