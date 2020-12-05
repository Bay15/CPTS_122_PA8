
#ifndef MapLoad_h
#define MapLoad_h

#include <SFML/Graphics.hpp>
#include <stack>
#include "entity.h"
#include "wall.h"


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
