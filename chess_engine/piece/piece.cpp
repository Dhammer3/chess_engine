#include "piece.h"
#include <cmath>
piece::piece(int value, sf::Sprite *image, sf::Vector2f scale, aliance::Enum a, piece_type::Enum pt)
{
	this->value = value;
	this->image = image;
	this->image->setScale(scale.x / 20, scale.y / 20);
	this->x_pos = 0;
	this->y_pos = 0;
	this->move_counter = 0;
	this->aliance = a;
	this->piece_type = pt;
}
// no piece can capture its own piece or put itself in check
bool piece::move(board *game_board, int x_pos, int y_pos)
{

	bool valid_move = true;
	// std::vector<int> king_pos = game_board->get_king_pos(this->aliance);
	// int &king_x = king_pos[0];
	// int &king_y = king_pos[1];
	board *game_board_copy = new board(*game_board);
	// game_board_copy->game_board[this->x_pos][this->y_pos] = NULL;
	// game_board_copy->game_board[x_pos][y_pos] = this;

	bool in_check = this->in_check(game_board, x_pos, y_pos);
	// make a mock move on a copy of the board
	// check if that board state puts the moving player in check.
	if (game_board->friendly_piece_in_location(this->aliance, x_pos, y_pos) || in_check)
	{
		valid_move = false;
	}
	// or putting self in check
	return valid_move;
}
void piece::set_position(int x, int y)
{
	this->image->setPosition(x * SQUARE_SIZE + OFFSET, y * SQUARE_SIZE + OFFSET);
	this->x_pos = x;
	this->y_pos = y;
}
void piece::increment_move_counter()
{
	this->move_counter += 1;
}
// if any enemy piece can move to the kings position before the move
bool piece::in_check(board *board, int x_pos, int y_pos)
{

	// static bool can_move_to_king_pos = false;
	// if (can_move_to_king_pos)
	// {
	// 	return true;
	// }
	static int recursion_counter = 0;
	if (recursion_counter == 0)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board->game_board[i][j])
				{

					piece *p = board->game_board[i][j];
					if (enemy_piece(p) && this->piece_type == piece_type::KING)
					{
						recursion_counter += 1;
						bool can_move_to_king_pos = p->move(board, x_pos, y_pos);
						if (can_move_to_king_pos)
						{
							std::cout << "cant move there" << std::endl;

							return true;
						}
					}
				}
			}
		}
	}

	recursion_counter = 0;
	return false;
}
bool piece::enemy_piece(piece *p)
{
	return this->aliance != p->aliance;
}
int piece::x_vector(int x_move)
{
	return this->x_pos - x_move;
}
int piece::y_vector(int y_move)
{
	return this->y_pos - y_move;
}
int piece::diagonal_vector(int x_move, int y_move)
{
	int x = this->x_vector(x_move);
	int y = this->y_vector(y_move);
	std::cout << "y " << y << std::endl;
	std::cout << "x " << x << std::endl;

	if (x == 0 || y == 0)
	{
		return 0;
	}
	int move_vector = sqrt(x * x + y * y);
	return move_vector;
}