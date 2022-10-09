#include "knight.h"

knight::knight(sf::Sprite *s, sf::Vector2f v, aliance::Enum a, int value) : piece(s, v, a, piece_type::KNIGHT, value) {}
bool knight::move(board *game_board, coordinates m)
{
	bool valid_coordinates = piece::move(game_board, m);
	if (!valid_coordinates)
	{

		return false;
	}
	int x_vector = this->x_vector(m.get_x());
	int y_vector = this->y_vector(m.get_y());
	if (abs(x_vector) == 2 && abs(y_vector) == 1 || abs(y_vector) == 2 && abs(x_vector) == 1)
	{
		valid_coordinates = true;
	}
	else
	{
		valid_coordinates = false;
	}

	return valid_coordinates;
}
