#include "piece.h"
#include "coordinates.h"

class king : public piece
{
public:
	king() {}
	king(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 100);
	bool move(board *game_board, coordinates m) override;
};
