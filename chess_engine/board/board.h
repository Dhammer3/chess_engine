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
		board(std::vector<piece*> pieces);
	private:	
		piece* game_board[8][8];
		piece* (*get_board())[8];
		void set_board(std::vector<piece*> pieces);

		
};
# endif