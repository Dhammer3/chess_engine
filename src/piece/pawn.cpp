#include "pawn.h"

pawn::pawn(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::PAWN, value) {}
bool pawn::move(board *game_board, int x_move, int y_move)
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

	// moving backwards
	if (this->aliance == aliance::BLACK && diff_y > 0 || this->aliance == aliance::WHITE && diff_y < 0)
	{
		valid_move = false;
	}
	if (x_squared > y_squared)
	{
		return false;
	}
	if (y_squared == 1 && x_squared == 0 && game_board->piece_in_location(x_move, y_move))
	{
		valid_move = false;
	}
	if (x_squared + y_squared >= 2)
	{

		if (x_squared > 1)
		{
			valid_move = false;
		}

		if (y_squared >= 2 && this->move_counter > 0 || y_squared > 4)
		{
			valid_move = false;
		}

		else if (x_squared == 1)
		{
			bool is_piece = (game_board->game_board[x_move][y_move]);
			if (!is_piece)
			{
				valid_move = false;
			}
		}
	}

	//! todo

	return valid_move;
}
