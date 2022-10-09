#include "piece.h"
class queen : public piece
{
public:
	queen() {}
	queen(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 9);
	bool move(board *game_board, coordinates m) override;
};
