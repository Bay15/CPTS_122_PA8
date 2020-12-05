#include "wall.h"

wall::wall()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setPosition(128, 128);
	rect.setFillColor(sf::Color::Cyan);
}
wall::wall(int height, int length)
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setPosition(height, length);
	rect.setFillColor(sf::Color::Transparent);
}

wall::~wall()
{
}