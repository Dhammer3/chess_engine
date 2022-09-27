#include "king.h"

king::king(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::KING, value) {}
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
		if (this->is_castling(game_board, x_move, y_move))
		{
			valid_move = true;
			int rook_x = this->x_vector(x_move) > 0 ? x_move - 2 : x_move + 1;
			int rook_x_move = this->x_vector(x_move) > 0 ? x_move + 1 : x_move - 1;
			// move the rook
			game_board->game_board[rook_x][y_move]->set_position(rook_x_move, y_move);
			game_board->game_board[rook_x][y_move]->increment_move_counter();
		}
		else
		{
			valid_move = false;
		}
	}

	//! todo

	return valid_move;
}
