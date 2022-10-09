#include "pawn.h"

pawn::pawn(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::PAWN, value) {}
bool pawn::move(board *game_board, coordinates m)
{
	bool valid_coordinates = piece::move(game_board, m);
	if (!valid_coordinates)
	{

		return false;
	}
	int diff_x = this->x_pos - m.get_x();
	int diff_y = this->y_pos - m.get_y();
	int x_squared = diff_x * diff_x;
	int y_squared = diff_y * diff_y;

	// moving backwards
	if (this->aliance == aliance::BLACK && diff_y > 0 || this->aliance == aliance::WHITE && diff_y < 0)
	{
		valid_coordinates = false;
	}
	if (x_squared > y_squared)
	{
		return false;
	}
	if (y_squared == 1 && x_squared == 0 && game_board->piece_in_location(m.get_x(), m.get_y()))
	{
		valid_coordinates = false;
	}
	if (x_squared + y_squared >= 2)
	{

		if (x_squared > 1)
		{
			valid_coordinates = false;
		}

		if (y_squared >= 2 && this->coordinates_counter > 0 || y_squared > 4)
		{
			valid_coordinates = false;
		}

		else if (x_squared == 1)
		{
			bool is_piece = (game_board->game_board[m.get_x()][m.get_y()]);
			if (!is_piece)
			{
				valid_coordinates = false;
			}
		}
	}

	//! todo

	return valid_coordinates;
}
