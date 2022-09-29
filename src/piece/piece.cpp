#include "piece.h"
#include "../board/board.h"
#include <cmath>
piece::piece(sf::Sprite *image, sf::Vector2f scale, aliance::Enum a, piece_type::Enum pt, int value)
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
// no piece can capture its own piece or put itself in chec

bool piece::move(board *game_board, int x_move, int y_move)
{
	if (x_move < 0 || x_move > 7 || y_move < 0 || y_move > 7)
	{
		return false;
	}
	bool in_check = false;
	bool valid_move = true;
	std::vector<int> king_pos = game_board->get_king_pos(this->aliance);
	bool null_king_pos = king_pos.empty();
	int &king_x = king_pos[0];
	int &king_y = king_pos[1];
	// copy the board
	board *game_board_copy = new board(*game_board);

	// make the mock move and set the king pos to empty
	if (!null_king_pos)
	{
		game_board_copy->game_board[this->x_pos][this->y_pos] = NULL;
		game_board_copy->game_board[king_x][king_y] = NULL;
		game_board_copy->game_board[x_move][y_move] = this;
		in_check = this->put_self_in_check(game_board_copy, x_move, y_move, king_x, king_y);
	}

	// if they are in check after the move, they cannot make that move.
	bool piece_in_way = this->piece_in_way(game_board, x_move, y_move);
	bool capturing_own_piece = game_board->capturing_own_piece(this->aliance, x_move, y_move);

	if (capturing_own_piece || in_check || piece_in_way)
	{
		valid_move = false;
	}

	return valid_move;
}
// todo
bool piece::is_castling(board *game_board, int x_move, int y_move)
{

	bool is_castling = false;
	bool two_space_x_move = abs(this->x_vector(x_move)) == 2;
	bool no_y_move = y_move == this->y_pos;
	bool first_move = this->move_counter == 0;
	int rook_x = this->x_vector(x_move) > 0 ? x_move - 2 : x_move + 1;
	bool is_piece = (game_board->game_board[rook_x][y_move]);
	piece rook;
	bool rook_can_castle = false;
	bool king_can_castle = two_space_x_move && no_y_move && first_move && !this->piece_in_way(game_board, rook_x, y_move);
	if (is_piece)
	{
		rook = *game_board->game_board[rook_x][y_move];
		rook_can_castle = rook.piece_type == piece_type::ROOK && rook.aliance == this->aliance && rook.move_counter == 0;
	}
	if (rook_can_castle && king_can_castle)
	{
		is_castling = true;
	}

	return is_castling;
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

bool piece::put_self_in_check(board *board, int x_move, int y_move, int king_x, int king_y)
{

	static int recursion_counter = 0;
	bool enemy_piece_can_move = false;
	if (recursion_counter == 0)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board->game_board[i][j])
				{

					piece *p = board->game_board[i][j];
					if (enemy_piece(p))
					{
						recursion_counter += 1;
						// the king is moving, check the spot it is moving to to see if it can move there.
						if (this->piece_type == piece_type::KING)
						{
							enemy_piece_can_move = p->move(board, x_move, y_move);
						}
						// if different piece is moving, check to see if any enemies can move to the kings position.
						else
						{
							enemy_piece_can_move = p->move(board, king_x, king_y);
						}
						if (enemy_piece_can_move)
						{
							std::cout << "cant put yourself in check!" << std::endl;
							return true;
						}
					}
				}
			}
		}
	}
	recursion_counter = 0;
	return enemy_piece_can_move;
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

	if (x == 0 || y == 0)
	{
		return 0;
	}
	int move_vector = sqrt(x * x + y * y);
	return move_vector;
}
bool piece::piece_in_way(board *game_board, int x_move, int y_move)
{
	// or if pieces in the way
	bool piece_in_way = false;
	int x_vector = this->x_vector(x_move) * -1;
	int y_vector = this->y_vector(y_move) * -1;
	int x = 0;
	int y = 0;

	if (this->piece_type != piece_type::KNIGHT)
	{
		while (x != x_vector || y != y_vector)
		{

			if (x != x_vector)
			{
				x_vector < 0 ? x-- : x++;
			}
			if (y != y_vector)
			{
				y_vector < 0 ? y-- : y++;
			}
			if ((this->x_pos + x) == x_move && (this->y_pos + y) == y_move)
			{
				break;
			}
			if (game_board->piece_in_location(this->x_pos + x, this->y_pos + y))
			{
				piece_in_way = true;
			}
		}
	}
	return piece_in_way;
}