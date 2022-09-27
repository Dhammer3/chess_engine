#include "rook.h"
rook::rook(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::ROOK, value) {}
bool rook::move(board *game_board, int x_move, int y_move)
{
	bool valid_move = piece::move(game_board, x_move, y_move);
	if (!valid_move)
	{
		return false;
	}
	int x_vector = this->x_vector(x_move);
	int y_vector = this->y_vector(y_move);
	int diagonal_vector = this->diagonal_vector(x_move, y_move);

	if (x_vector != 0 || y_vector != 0)
	{
		// moving like a rook
		if (diagonal_vector == 0)
		{
			valid_move = true;
		}
	}
	return valid_move;
}
