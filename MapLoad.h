
#ifndef MapLoad_h
	#define MapLoad_h

	#include <SFML/Graphics.hpp>
	#include <stack>

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

class wall : public Entity
{
private:
	/* data */
public:
	wall();
	wall(int, int);
	//virtual wall newwall();
	~wall();
};

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

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	void doquad(sf::Vertex*& quad, sf::Vector2u tileSize, int tu, int tv, int i, int j)
	{
		//width,length
		quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
		quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
		quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
		quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

		quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
		quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
		quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
		quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
	}

	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height, std::vector<wall>& wallArray, std::vector<wall>& winArray, std::vector<wall>& lavaArray)
	{
		// load the tileset texture
		if (!m_tileset.loadFromFile(tileset)) // is done
			return false;

		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads); //can be written
		m_vertices.resize(width * height * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j) //can be written
			{

				// get the current tile number
				int tileNumber = tiles[i + j * width];

				// find its position in the tileset texture
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x); ///////////////this is where i am
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				doquad(quad, tileSize, tu, tv, i, j);
				if (tileNumber == 0) //put a wall here
				{
					wall* wall1;
					wall1 = new wall(i * 64, j * 64);

					wallArray.push_back(*wall1);
				}
				else if (tileNumber == 2) //green win bolocks
				{
					wall* wall1;
					wall1 = new wall(i * 64, j * 64);

					winArray.push_back(*wall1);
				}
				else if (tileNumber == 3) //lava blocks
				{
					wall* wall1;
					wall1 = new wall(i * 64, j * 64);

					lavaArray.push_back(*wall1);
				}
			}

		return true;
	}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

protected:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

#endif // !gameTile_h

/*
void map_generation(std::vector<std::vector<bool>>& not_visited, std::vector<std::vector<int>>& it_is, std::stack<int>& x, std::stack<int>& y, int& a, int& b);
void map_generation(std::vector<std::vector<bool>>& not_visited, std::vector<std::vector<int>>& it_is, std::stack<int>& x, std::stack<int>& y, int& a, int& b)
{
	not_visited[a][b] = false;
	it_is[a][b] = rand() % 2;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
			case 0:

				a--;

				break;
			case 1:

				a += 2;

				break;
			case 2:

				a--;
				b--;

				break;
			case 3:

				b += 2;
				break;

			default:
				continue;
				break;
		}

		if (not_visited[a][b])
		{
			//it_is[a][b] = rand() % 2;
			x.push(a);
			y.push(b);
			map_generation(not_visited, it_is, x, y, a, b);
		}
	}
	a = x.top();
	x.pop();
	b = y.top();
	y.pop();
}


// class Cell
// {
// private:
// 	// Entity middle(sf::Texture, int, int, int, int);

// 	// Entity l_wall(sf::Texture, int, int, int, int);
// 	// Entity R_wall(sf::Texture, int, int, int, int);
// 	// Entity T_wall(sf::Texture, int, int, int, int);
// 	// Entity B_wall(sf::Texture, int, int, int, int);

// 	// Entity TL_corner(sf::Texture, int, int, int, int);
// 	// Entity TR_corner(sf::Texture, int, int, int, int);
// 	// Entity BR_corner(sf::Texture, int, int, int, int);
// 	// Entity BL_corner(sf::Texture, int, int, int, int);

// protected:
// public:
// 	Cell();

// 	Cell(sf::Texture mid, sf::Texture L, sf::Texture R, sf::Texture T, sf::Texture B, sf::Texture C, sf::Vertex*& quad, int i, int j) //doquad
// 	{
// 		Entity middle(mid, 56, 56, 0, 0);

// 		Entity l_wall(L, 4, 56, 0, 4);
// 		Entity R_wall(R, 4, 56, 56, 4);
// 		Entity T_wall(T, 56, 4, 4, 0);
// 		Entity B_wall(B, 56, 4, 4, 56);

// 		Entity TL_corner(C, 4, 4, 0, 0);
// 		Entity TR_corner(C, 4, 4, 0, 56);
// 		Entity BR_corner(C, 4, 4, 56, 56);
// 		Entity BL_corner(C, 4, 4, 0, 56);

// 		middle.doquad(quad, i, j);
// 		l_wall.doquad(quad, i, j);
// 		R_wall.doquad(quad, i, j);
// 		T_wall.doquad(quad, i, j);
// 		B_wall.doquad(quad, i, j);
// 		TL_corner.doquad(quad, i, j);
// 		TR_corner.doquad(quad, i, j);
// 		BR_corner.doquad(quad, i, j);
// 		BL_corner.doquad(quad, i, j);
// 	}

// 	void makewall()
// 	{
// 		//TODO add rectangle
// 		//TODO add diffrent sprite
// 	}

// 	//TODO cell wall editer
// };

// class board : public sf::Drawable, public sf::Transformable
// {
// private:
// 	//

// 	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
// 	{
// 		// apply the transform
// 		states.transform *= getTransform();

// 		// apply the tileset texture
// 		//states.texture = &m_tileset;

// 		// draw the vertex array
// 		target.draw(m_vertices, states);
// 	}

// 	void build_wall(Cell* ptr_)
// 	{
// 		ptr_->makewall();
// 	}

// protected:
// public:
// 	sf::VertexArray m_vertices;
// 	//sf::Texture m_tileset; //may not be neededc

// 	bool Load(unsigned int width, unsigned int height)
// 	{
// 		Cell* ptr_;

// 		sf::Texture mid;
// 		sf::Texture L;
// 		sf::Texture R;
// 		sf::Texture T;
// 		sf::Texture B;
// 		sf::Texture C;

// 		mid.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\mid.png");
// 		L.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\edge.png");
// 		R.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\edge.png");
// 		T.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\flat.png");
// 		B.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\flat.png");
// 		C.loadFromFile("C:\\Users\\caden\\newtest\\src\\images\\corner.png");

// 		m_vertices.setPrimitiveType(sf::Quads); // is written
// 		m_vertices.resize(width * height * 4 * 7);

// 		for (unsigned int i = 0; i < width; ++i)
// 		{
// 			for (unsigned int j = 0; j < height; ++j) //can be written
// 			{
// 				//int tileNumber = tiles[i + j * width];

// 				// TODO find its position in the tileset texture
// 				//int tu = tileNumber % (m_tileset.getSize().x / tileSize.x); ///////////////this is where i am
// 				//int tv = tileNumber / (m_tileset.getSize().x / tileSize.x); //texture

// 				// TODO get a pointer to the current tile's quad
// 				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

// 				ptr_ = new Cell(mid, L, R, T, B, C, quad, i, j);

// 				build_wall(ptr_);
// 				//ptr_ = nullptr;
// 				//doquad(quad, tileSize, tu, tv, i, j);
// 			}
// 		}
// 		//CPTS: Kathryn Jackson or Paul Wilmoth		engineering 304 316
// 		//boiling coollege carrer services
// 		//	sandy brab 		anna yurkin

// 		return true;
// 	}
// };



*/
