#ifndef wall_h
#define wall_h

#include <SFML/Graphics.hpp>
#include <stack>
#include "entity.h"


class wall : public Entity
{
public:
	wall();
	wall(int, int);
	~wall();
};


#endif // !wall_h
