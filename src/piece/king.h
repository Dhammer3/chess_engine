#include "piece.h"
class king : public piece
{
public:
	king(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 100);
	bool move(board *game_board, int x, int y) override;
};
