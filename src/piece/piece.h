#if !defined(__PIECE_H__)
#define __PIECE_H__
#include "aliance.hpp"
#include "piece_type.hpp"
#include "board.h"
#include "piece_factory.h"
#include "coordinates.h"
#include <iostream>
#include <cmath>
#include <thread>
#include <future>
#include <SFML/Graphics.hpp>
class board;
class piece : sf::Sprite
{
public:
	piece() {}
	piece(sf::Sprite *image, sf::Vector2f scale, aliance::Enum a, piece_type::Enum pt, int value);
	~piece() {}
	virtual bool move(board *game_board, coordinates m);
	int value;
	int x_pos, y_pos, coordinates_counter;
	sf::Sprite *image;
	aliance::Enum aliance;
	piece_type::Enum piece_type;
	void set_position(int x, int y);
	bool is_castling(board *game_board, coordinates m);

	void increment_move_counter();
	bool put_self_in_check(board *game_board, coordinates m, coordinates king_coordinates);
	bool enemy_piece(piece *p);
	int x_vector(int x_pos);
	int y_vector(int y_pos);
	int diagonal_vector(coordinates m);
	bool piece_in_way(board *game_board, coordinates m);
};
#endif
