# if !defined(__BOARD_H__)
#define __BOARD_H__
#include "../piece/piece.h"
const int OFFSET =-2;
const int WINDOW_SIZE=455;
const float SQUARE_SIZE = WINDOW_SIZE/8;
class piece;
class board
{
	public:
		board();
		board(std::vector<piece*> pieces, sf::RenderWindow& window , sf::Sprite *image);
		sf::RenderWindow *window;
		sf::Sprite *board_image;
		piece* game_board[8][8];
		piece* (*get_board())[8];
		void clear_board();
		void set_board(std::vector<piece*> pieces);
		bool piece_in_location(int x, int y);
		bool friendly_piece_in_location(aliance::Enum a, int x, int y);
		void draw_board(std::vector<piece*> pieces);
		std::vector<int> get_king_pos(aliance::Enum a);


		
};
# endif