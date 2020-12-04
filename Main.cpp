#include "MapLoad.h"
#include "Platform/Platform.hpp"
#include "player.h"
#include <algorithm>
#include <ctime>
#include <stack>
#include <vector>
#define pixel_length 64
//https://www.youtube.com/watch?v=bx3--22D4E4

int main()
{
	srand(time(NULL));
	// create the window
	// define the level with an array of tile indices
	std::vector<int> level = {};
	std::vector<int> temp = {};

	std::stack<int> X;
	std::stack<int> Y;
	int height, width;

	height = 8;
	width = 16;

	height++;
	width++;
	height++;
	width++;

	//	std::vector		<std::vector<int>> 			v(10, std::vector<int>(5));
	std::vector<std::vector<bool>> move(height, std::vector<bool>(width));

	std::vector<std::vector<int>> it_is(height, std::vector<int>(width));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			move[i][j] = true;
			it_is[i][j] = 1;
		}
	}

	//seedmap();
	//int x = 0, y = 0;
	//map_generation(move, it_is, X, Y, x, y);

	//int c = 1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 1 && j == 1)
				level.push_back(4);
			else if (i == (height - 2) && j == (width - 2))
				level.push_back(2);
			else if (0 == i || 0 == j || i == (height - 1) || j == (width - 1))
				level.push_back(0);
			else
			{
				//c = it_is[i][j];
				level.push_back(it_is[i][j]);
			}
		}
	}

	sf::RenderWindow window(sf::VideoMode(width * pixel_length, height * pixel_length), "Tilemap");

	//
	std::vector<wall> wallArray;
	std::vector<wall> winArray;
	std::vector<wall> lavaArray;
	// create the tilemap from the level definition

	TileMap map;

	if (!map.load("C:\\Users\\caden\\newtest\\src\\images\\tileset.png", sf::Vector2u(pixel_length, pixel_length), level, width, height, wallArray, winArray, lavaArray))
		return -1;

	//board map;

	//if (!map.Load(width, height))
	//	return -1;

	player player1;

	sf::Texture texture;
	texture.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\BlobSheet.png");

	//TODO run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.draw(player1.sprite);

		player1.move(wallArray, winArray, lavaArray);

		window.display();
	}

	return 0;
}