#include "piece.h"
#include "coordinates.h"
class bishop : public piece
{
public:
	bishop() {}
	bishop(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 3);
	bool move(board *game_board, coordinates m) override;
};
