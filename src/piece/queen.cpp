#include "queen.h"
#include <cmath>
queen::queen(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::QUEEN, value) {}
bool queen::move(board *game_board, coordinates m)
{
	bool valid_move = piece::move(game_board, m);
	if (!valid_move)
	{
		return false;
	}
	int x_vector = this->x_vector(m.get_x());
	int y_vector = this->y_vector(m.get_y());
	int diagonal_vector = this->diagonal_vector(m);

	if (x_vector != 0 || y_vector != 0)
	{
		// moving like a rook
		if (diagonal_vector == 0)
		{
			valid_move = true;
		}

		// moving like a bishop
		else if (abs(x_vector) == abs(y_vector))
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
