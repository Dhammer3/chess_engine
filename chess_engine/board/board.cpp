#include "board.h"
board::board(std::vector<piece*> pieces)
{
 	for (int i=0; i<pieces.size(); i++)
	{
        piece* p = pieces[i];
        this->game_board[p->x_pos][p->y_pos]=p;
    }
};
void board::set_board(std::vector<piece*> pieces)
{
 	for (int i=0; i<pieces.size(); i++)
	{
        piece* p = pieces[i];
        this->game_board[p->x_pos][p->y_pos]=p;
    }
};
piece* (*board::get_board())[8] 
{
 return this->game_board;
};