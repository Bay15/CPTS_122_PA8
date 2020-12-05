#include "player.h"

player::player() //constructor
{
	texture.loadFromFile("Resources/BlobSheet.png"); //establishes the textrue position and allows the player to initially move.
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
	playerspeed = 4;
}

void player::resetPlayer() //resets the player information 
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
	playerspeed = 4;
}

bool player::colide(std::vector<wall> Array, int counter) //determines if the player is next to a wall
{
	if (sprite.getGlobalBounds().intersects(Array[counter].rect.getGlobalBounds())) //if the player is touching a wall return true
		return true;

	return false;
}

void player::can_move(std::vector<wall> wallArray, sf::View& view1) //determines if the player can move 
{
	bool hit;
	int counter = 0;
	std::vector<wall>::const_iterator iter1;
	for (iter1 = wallArray.begin(); iter1 != wallArray.end(); iter1++, counter++) //determines iif the player is next to each wall
	{
		hit = colide(wallArray, counter); //if the player is touching a wall hit is true
		if (hit) //hit the wall 
		{

			if (direction == 0) //if the player is facing up towards the wall
			{
				can_move_up = false; //illegal to move up
				sprite.move(0, 1 * playerspeed);
				view1.move(0, 1 * playerspeed);
			}
			else if (direction == 2) //if the player is facing down towards the wall
			{
				can_move_down = false;  //illegal to move down
				sprite.move(0, -1 * playerspeed);
				view1.move(0, - 1 * playerspeed);
			}
			else if (direction == 1) //if the player is facing left towards the wall
			{
				can_move_left = false; //illegal to move left
				sprite.move(1 * playerspeed, 0);
				view1.move(1 * playerspeed,0);
			}
			else if (direction == -1)  //if the player is facing right towards the wall
			{
				can_move_right = false; //illegal to move right
				sprite.move(-1 * playerspeed, 0);
				view1.move(-1 * playerspeed,0);
			}
		}
	}
}

void player::didwin(std::vector<wall> winArray) //determines if the player won
{
	std::vector<wall>::const_iterator iter1; 
	int counter = 0;
	for (iter1 = winArray.begin(); iter1 != winArray.end(); iter1++, counter++) //sees if the player is touching the win block
	{
		win = colide(winArray, counter); //win is true if the player is 
	}
}

bool player::getWin() //retrives win status
{
	return win; 
}

void player::dead(std::vector<wall> lavaArray) //determines if the player is dead
{
	std::vector<wall>::const_iterator iter1;
	int counter = 0;
	for (iter1 = lavaArray.begin(); iter1 != lavaArray.end(); iter1++, counter++) //sees if the player is touching a lava block
	{
		alive = colide(lavaArray, counter); //alive is set to false if the player is 
		if (alive)
			alive = false; //if alive is set to true set reset it to false
		else
		{
			alive = true; //otherwise set it to true
		}
	}
}

bool player::getAlive() //retrives the alive status
{
	return alive;
}

void player::move(std::vector<wall> wallArray, std::vector<wall> winArray, std::vector<wall> lavaArray, sf::View& view1) //move function
{
	can_move(wallArray,view1);
	dead(lavaArray);
	if (alive)
		;
	else //if the player is not alive
	{
		return;
	}
	didwin(winArray); 
	if (win) //if the player already won
	{
		return; 
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //if down or S button is being pressed
	{
		direction = 2;  //set direction
		can_move(wallArray,view1);
		if (can_move_down) //if the player is allowed to move down
		{
			sprite.move(0, 1 * playerspeed); //move downward
			view1.move(0, 1 * playerspeed);
			sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //if up or W button is being pressed
	{
		direction = 0; //set direction
		can_move(wallArray,view1);
		if (can_move_up) //if the player is allowed to move up
		{
			sprite.move(0, -1 * playerspeed); //move up
			view1.move(0, -1 * playerspeed);
			sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //if left or A button is being pressed
	{
		direction = 1; //set direction
		can_move(wallArray,view1);
		if (can_move_left) //if the player is allowed to move left 
		{
			sprite.move(-1 * playerspeed, 0); //move left 
			view1.move(-1 * playerspeed,0);
			sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //if the right or D button is being pressed 
	{
		direction = -1; //set direction
		can_move(wallArray,view1);
		if (can_move_right) //if the player is allowed to move right 
		{
			sprite.move(1 * playerspeed, 0); //move right 
			view1.move(1 * playerspeed,0);
			sprite.setTextureRect(sf::IntRect(96, 0, 32, 32));
		}
	}
	can_move_down = true; //reset to the player being able to move 
	can_move_up = true;
	can_move_right = true;
	can_move_left = true;
}
