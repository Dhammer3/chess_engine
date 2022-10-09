#include "unit_tests.h"

unit_tests::unit_tests(piece_factory pf)
{
	// piece_factory pf(scale);
	this->scale = pf.scale;
	this->pf = pf;
	this->game_board = new board(pf.get_pieces());
}
void unit_tests::reset_board()
{
	piece_factory pf(this->scale);
	this->pf = pf;
	this->game_board = new board(pf.get_pieces());
}
// TESTS
void unit_tests::run_all_tests()
{
	check();
}
void unit_tests::put_self_in_check()
{
	// wpawn
	this->game_board->game_board[4][6]->set_position(4, 4);
	// black pawn
	this->game_board->game_board[3][1]->set_position(3, 3);
	// wQueen
	this->game_board->game_board[3][7]->set_position(6, 4);
	this->game_board->set_board(this->pf.get_pieces());

	// try to move the black king to the in-check pos
	coordinates m(3, 1);
	IS_TRUE(!this->game_board->game_board[4][0]->move(this->game_board, m));
	this->reset_board();
}

void unit_tests::put_other_player_in_check()
{
	// wpawn
	this->game_board->game_board[4][6]->set_position(4, 4);
	// black pawn
	this->game_board->game_board[3][1]->set_position(3, 3);
	// bking
	this->game_board->game_board[4][0]->set_position(3, 1);

	this->game_board->set_board(this->pf.get_pieces());

	// move the wqueen to the in-check pos
	coordinates m(6, 4);

	IS_TRUE(this->game_board->game_board[3][7]->move(this->game_board, m));
	this->reset_board();
}
void unit_tests::check()
{
	put_other_player_in_check();
	put_self_in_check();
}
