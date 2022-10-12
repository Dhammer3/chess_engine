#include "piece.h"
#include "../board/board.h"
#include "coordinates.h"
bool putting_self_in_check = false;
int recursion_counter = 0;
piece::piece(sf::Sprite *image, sf::Vector2f scale, aliance::Enum a, piece_type::Enum pt, int value)
{
	this->value = value;
	this->image = image;
	this->image->setScale(scale.x / 20, scale.y / 20);
	this->x_pos = 0;
	this->y_pos = 0;
	this->coordinates_counter = 0;
	this->aliance = a;
	this->piece_type = pt;
}
// no piece can capture its own piece or put itself in chec

bool piece::move(board *game_board, coordinates m)
{

	if (m.get_x() < 0 || m.get_x() > 7 || m.get_y() < 0 || m.get_y() > 7)
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

	// make the mock coordinates and set the king pos to empty
	if (!null_king_pos)
	{
		coordinates king_position(king_x, king_y);

		game_board_copy->game_board[this->x_pos][this->y_pos] = NULL;
		game_board_copy->game_board[king_x][king_y] = NULL;
		game_board_copy->game_board[m.get_x()][m.get_y()] = this;

		in_check = this->put_self_in_check(game_board_copy, m, king_position);
		putting_self_in_check = false;
	}

	// if they are in check after the coordinates, they cannot make that coordinates.
	bool piece_in_way = this->piece_in_way(game_board, m);
	bool capturing_own_piece = game_board->capturing_own_piece(this->aliance, m);
	bool capturing_king = game_board->capturing_king(m);
	if (capturing_own_piece || in_check || piece_in_way || capturing_king)
	{
		valid_move = false;
	}

	return valid_move;
}
// todo
bool piece::is_castling(board *game_board, coordinates m)
{

	bool is_castling = false;
	bool two_space_move = abs(this->x_vector(m.get_x())) == 2;
	bool no_y_move = m.get_y() == this->y_pos;
	bool first_move = this->coordinates_counter == 0;
	int rook_x = this->x_vector(m.get_x()) > 0 ? m.get_x() - 2 : m.get_x() + 1;
	coordinates rook_coords(rook_x, m.get_y());
	bool is_piece = game_board->piece_in_location(rook_coords);
	bool rook_can_castle = false;
	bool king_can_castle = two_space_move && no_y_move && first_move && !this->piece_in_way(game_board, rook_coords);
	if (is_piece)
	{
		piece *rook = game_board->game_board[rook_x][m.get_y()];
		rook_can_castle = rook->piece_type == piece_type::ROOK && rook->aliance == this->aliance && rook->coordinates_counter == 0;
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
	this->coordinates_counter += 1;
}

bool piece::put_self_in_check(board *board, coordinates m, coordinates king_pos)
{
	piece_factory *pf = new piece_factory();
	piece *p = new piece();
	static int recursion_counter = 0;

	if (putting_self_in_check)
	{
		recursion_counter = 0;

		return true;
	}
	bool enemy_piece_can_coordinates = false;
	if (recursion_counter == 0)
	{

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board->game_board[i][j])
				{

					p = board->game_board[i][j];
					if (enemy_piece(p))
					{
						recursion_counter += 1;
						// the king is moving, check the spot it is moving to to see if it can coordinates there.
						if (this->piece_type == piece_type::KING)
						{
							board->game_board[m.get_x()][m.get_y()] = pf->make_piece(this->aliance, piece_type::PAWN);
							// auto chkmt = std::async(&piece::mo, this, m.get_x()m, m.get_y()m);
							auto can_coordinates = std::async(&piece::move, p, board, m);
							putting_self_in_check = can_coordinates.get();
						}
						// if different piece is moving, check to see if any enemies can coordinates to the kings position.
						else
						{

							putting_self_in_check = p->move(board, king_pos);
						}
						if (putting_self_in_check)
						{
							recursion_counter = 0;

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
int piece::diagonal_vector(coordinates m)
{
	int x = this->x_vector(m.get_x());
	int y = this->y_vector(m.get_y());

	if (x == 0 || y == 0)
	{
		return 0;
	}
	int coordinates_vector = sqrt(x * x + y * y);
	return coordinates_vector;
}
bool piece::piece_in_way(board *game_board, coordinates m)
{
	// or if pieces in the way
	bool piece_in_way = false;
	int x_vector = this->x_vector(m.get_x()) * -1;
	int y_vector = this->y_vector(m.get_y()) * -1;
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
			if ((this->x_pos + x) == m.get_x() && (this->y_pos + y) == m.get_y())
			{
				break;
			}
			coordinates temp(this->x_pos + x, this->y_pos + y);
			if (game_board->piece_in_location(temp))
			{
				piece_in_way = true;
			}
		}
	}
	return piece_in_way;
}