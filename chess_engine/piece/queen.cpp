#include "queen.h"
queen::queen(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a):piece(value, s, v, a){}	
bool queen::move( int x_pos, int y_pos)
	{
		return true;
	}
