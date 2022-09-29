#include "piece.h"
class bishop : public piece
{
public:
	bishop() {}
	bishop(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 3);
	bool move(board *game_board, int x, int y) override;
};
