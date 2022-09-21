#include "queen.h"
#include <cmath>
queen::queen(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a) : piece(value, s, v, a, piece_type::QUEEN) {}
bool queen::move(board *game_board, int x_move, int y_move)
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
			std::cout << "here" << std::endl;
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
