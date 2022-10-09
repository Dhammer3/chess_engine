#if !defined(__BOARD_H__)
#define __BOARD_H__
#include "../piece/piece.h"
#include <SFML/Graphics.hpp>

const int OFFSET = -2;
const int WINDOW_SIZE = 455;
const float SQUARE_SIZE = WINDOW_SIZE / 8;
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
	bool piece_in_location(int x, int y);
	piece *get_piece(int x, int y);
	bool capturing_own_piece(aliance::Enum a, int x, int y);
	bool capturing_king(int x, int y);
	void draw_board(std::vector<piece *> pieces);
	void remove_piece(piece *p);
	bool checkmate(aliance::Enum a);
	bool in_check(aliance::Enum a, int kingX, int kingY); // refactor?
	bool in_checkmate(aliance::Enum);
	bool checkmate_helper(std::vector<piece *> pieces, aliance::Enum a);

	std::vector<int> get_king_pos(aliance::Enum a);
};
#endif
