#include "piece.h"
class queen:public piece
{
public:
	queen(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a);
	bool move(int x, int y);
};
