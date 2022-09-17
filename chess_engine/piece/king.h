#include "piece.h"
class king:public piece
{
public:
	king(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a);
	bool move(int x, int y);
};
