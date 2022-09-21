#if !defined(__PIECE_H__)
#define __PIECE_H__
#include "aliance.hpp"
#include "piece_type.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../board/board.h"
class board;
class piece : sf::Sprite
{
public:
	piece() {}
	piece(int value, sf::Sprite *image, sf::Vector2f scale, aliance::Enum a, piece_type::Enum pt);
	virtual bool move(board *game_board, int x_pos, int y_pos);
	int value;
	int x_pos, y_pos, move_counter;
	sf::Sprite *image;
	aliance::Enum aliance;
	piece_type::Enum piece_type;
	void set_position(int x, int y);
	void increment_move_counter();
	bool in_check(board *game_board, int kingX, int kingY);
	bool enemy_piece(piece *p);
	int x_vector(int x_move);
	int y_vector(int y_move);
	int diagonal_vector(int x_move, int y_move);
};
#endif
