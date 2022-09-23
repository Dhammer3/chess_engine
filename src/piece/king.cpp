#include "king.h"

king::king(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a) : piece(value, s, v, a, piece_type::KING) {}
bool king::move(board *game_board, int x_move, int y_move)
{
	bool valid_move = piece::move(game_board, x_move, y_move);
	if (!valid_move)
	{

		return false;
	}
	int diff_x = this->x_pos - x_move;
	int diff_y = this->y_pos - y_move;
	int x_squared = diff_x * diff_x;
	int y_squared = diff_y * diff_y;

	if (x_squared + y_squared > 2)
	{
		valid_move = false;
	}

	return valid_move;
}
