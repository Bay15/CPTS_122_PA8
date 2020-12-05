#ifndef entity_h
#define entity_h

#include <SFML/Graphics.hpp>

//	Enity
//	used in wall class, used in player class
//	used for a base of what things have
//	
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
