#if !defined(__BOARD_H__)
#define __BOARD_H__
#include "piece.h"
#include <SFML/Graphics.hpp>
const int OFFSET = -2;
const int WINDOW_SIZE = 455;
const float SQUARE_SIZE = WINDOW_SIZE / 8;
class coordinates;
class piece;
class board
{
public:
	board(){};
	board(std::vector<piece *> pieces);
	board(std::vector<piece *> pieces, sf::RenderWindow &window, sf::Sprite *image);
	~board(){};
	sf::RenderWindow *window;
	sf::Sprite *board_image;
	std::vector<piece *> pieces;
	bool foo;
	piece *game_board[8][8];
	piece *(*get_board())[8];
	void clear_board();
	void set_board(std::vector<piece *> pieces);
	bool piece_in_location(coordinates move);
	piece *get_piece(coordinates piece_loc);
	bool capturing_own_piece(aliance::Enum a, coordinates move);
	bool capturing_king(coordinates move);
	void draw_board(std::vector<piece *> pieces);
	void remove_piece(piece *p);
	std::vector<piece *> get_enemy_pieces(aliance::Enum a);
	bool in_check(aliance::Enum a);
	bool in_check_helper(std::vector<piece *> pieces, aliance::Enum a, coordinates king_position, board *game_board_copy);
	bool checkmate(aliance::Enum a);
	bool checkmate_helper(std::vector<piece *> pieces, aliance::Enum a);

	std::vector<int> get_king_pos(aliance::Enum a);
};
#endif
