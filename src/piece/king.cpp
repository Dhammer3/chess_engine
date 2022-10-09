#include "king.h"

king::king(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::KING, value) {}
bool king::move(board *game_board, coordinates m)
{
	bool valid_move = piece::move(game_board, m);
	if (!valid_move)
	{

		return false;
	}
	int diff_x = this->x_pos - m.get_x();
	int diff_y = this->y_pos - m.get_y();
	int x_squared = diff_x * diff_x;
	int y_squared = diff_y * diff_y;

	if (x_squared + y_squared > 2)
	{
		if (this->is_castling(game_board, m))
		{
			valid_move = true;
			int rook_x = this->x_vector(m.get_x()) > 0 ? m.get_x() - 2 : m.get_x() + 1;
			int rook_y = m.get_y();
			coordinates new_rook_coords(rook_x + (diff_x < 0 ? diff_x : diff_x + 1), rook_y);
			// move the rook
			game_board->game_board[rook_x][m.get_y()]->set_position(new_rook_coords.get_x(), new_rook_coords.get_y());
			game_board->game_board[rook_x][m.get_y()]->increment_move_counter();
		}
		else
		{
			valid_move = false;
		}
	}

	//! todo

	return valid_move;
}
