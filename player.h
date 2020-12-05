#include <SFML/Graphics.hpp>
#include <iostream>
#include "entity.h"
#include "MapLoad.h"

#ifndef PLAYER_H
#define PLAYER_H

class player : public Entity
{
private:
	int direction;
	bool can_move_up, can_move_down, can_move_right, can_move_left;
	bool alive;
	bool win;
	int playerspeed;

public:
	player();

	void resetPlayer();

	bool colide(std::vector<wall> Array, int counter);

	void can_move(std::vector<wall> wallArray, sf::View& view1);

	void didwin(std::vector<wall> winArray);

	bool getWin();

	void dead(std::vector<wall> lavaArray);

	bool getAlive();

	void move(std::vector<wall> wallArray, std::vector<wall> winArray, std::vector<wall> lavaArray, sf::View& view1);
};

#endif
