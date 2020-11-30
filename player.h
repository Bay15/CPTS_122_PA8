#include <iostream>
#define using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player 
{
	private:
		
		int health;
		int x_coordinate;
		int y_coordinate;
		
	public:

		player() 
		{
			//sets coordinates to starting position
		}

		void move(char command) 
		{
			if (command == 'w')
			{
				move_up();
			}
			else if (command == 'a')
			{
				move_left();
			}
			else if (command == 's')
			{
				move_down();
			}
			else if (command == 'd')
			{
				move_right();
			}
		}

		void move_up() 
		{
			y_coordinate -= 5; //move up 5 pixels
		}

		void move_down()
		{
			y_coordinate += 5; //move down 5 pixels
		}

		void move_right()
		{
			x_coordinate += 5; //move right 5 pixels
		}

		void move_left()
		{
			x_coordinate -= 5; //move left 5 pixels
		}
};

#endif

