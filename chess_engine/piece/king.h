#include "piece.h"
class king:public piece
{
public:
	king(int value, sf::Sprite *s, sf::Vector2f v);
	void move(int x, int y);
};
