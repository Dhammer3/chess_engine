#include "piece.h"
class pawn : public piece
{
public:
	pawn() {}
	pawn(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value = 100);
	bool move(board *game_board, coordinates mvoe) override;
};
