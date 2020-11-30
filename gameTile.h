
#ifndef gameTile_h
#define gameTile_h

#include <SFML/Graphics.hpp>

class GameTile
{
public:
	bool isPassable;
	bool isExit;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;

	GameTile(std::string, float, float, bool, bool);
	bool setUpSprite(std::string);
};


#endif // !gameTile_h



