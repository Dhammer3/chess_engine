#include "piece.h"
class rook : public piece
{
public:
	rook(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 5);
	bool move(board *game_board, int x, int y);
};
