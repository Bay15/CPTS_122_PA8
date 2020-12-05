#include "player.h"

player::player()
{
	texture.loadFromFile("Resources/BlobSheet.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	sprite.setPosition(64 + 16, 64 + 16); //starting position
	direction = -1;
	can_move_down = true;
	can_move_up = true;
	can_move_right = true;
	can_move_left = true;
	alive = true;
	win = false;
	playerspeed = 16;
}

bool player::colide(std::vector<wall> Array, int counter)
{
	if (sprite.getGlobalBounds().intersects(Array[counter].rect.getGlobalBounds()))
		return true;

	return false;
}

void player::can_move(std::vector<wall> wallArray)
{
	bool hit;
	int counter = 0;
	std::vector<wall>::const_iterator iter1;
	for (iter1 = wallArray.begin(); iter1 != wallArray.end(); iter1++, counter++)
	{
		hit = colide(wallArray, counter);
		if (hit) //hit the wall
		{

			if (direction == 0) //move up
			{
				can_move_up = false;
				sprite.move(0, 1 * playerspeed);
			}
			else if (direction == 2) //move down
			{
				can_move_down = false;
				sprite.move(0, -1 * playerspeed);
			}
			else if (direction == 1) //move left
			{
				can_move_left = false;
				sprite.move(1 * playerspeed, 0);
			}
			else if (direction == -1) //move right
			{
				can_move_right = false;
				sprite.move(-1 * playerspeed, 0);
			}
		}
	}
}

void player::didwin(std::vector<wall> winArray)
{
	std::vector<wall>::const_iterator iter1;
	int counter = 0;
	for (iter1 = winArray.begin(); iter1 != winArray.end(); iter1++, counter++)
	{
		win = colide(winArray, counter);
	}
}

bool player::getWin()
{
	return win;
}

void player::dead(std::vector<wall> lavaArray)
{
	std::vector<wall>::const_iterator iter1;
	int counter = 0;
	for (iter1 = lavaArray.begin(); iter1 != lavaArray.end(); iter1++, counter++)
	{
		alive = colide(lavaArray, counter);
		if (alive)
			alive = false;
	}
}

bool player::getAlive()
{
	return alive;
}

void player::move(std::vector<wall> wallArray, std::vector<wall> winArray, std::vector<wall> lavaArray) //,lava array,win array
{
	can_move(wallArray);
	dead(lavaArray);
	if (alive)
		;
	else
	{
		return; //died
	}
	didwin(winArray);
	if (win)
	{
		return; //win
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = 2;

		can_move(wallArray);
		if (can_move_down)
		{
			sprite.move(0, 1 * playerspeed);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		direction = 0;
		can_move(wallArray);
		if (can_move_up)
		{
			sprite.move(0, -1 * playerspeed);
			sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		direction = 1;
		can_move(wallArray);
		if (can_move_left)
		{
			sprite.move(-1 * playerspeed, 0);
			sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = -1;
		can_move(wallArray);
		if (can_move_right)
		{
			sprite.move(1 * playerspeed, 0);
			sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
		}
	}
	can_move_down = true;
	can_move_up = true;
	can_move_right = true;
	can_move_left = true;
}