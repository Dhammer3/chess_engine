#include "bishop.h"

bishop::bishop(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::BISHOP, value) {}
bool bishop::move(board *game_board, int x_move, int y_move)
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
		if (abs(x_vector) == abs(y_vector))
		{
			valid_move = true;
		}
		else
		{
			valid_move = false;
		}
	}
	return valid_move;
}
