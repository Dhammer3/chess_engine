// this class keeps track of moves and board states
#include "game_info.h"
game_info::game_info(board board_state, coordinates position, coordinates move)
{
    this->board_state = board_state;
    this->position = position;
    this->move = move;
    std::future<bool> white_in_check = std::async(&board::in_check, board_state, aliance::WHITE);
    std::future<bool> black_in_check = std::async(&board::in_check, board_state, aliance::BLACK);
    // std::async(&board::in_check, board_state, aliance::WHITE);

    // std::async(&board::
    this->white_in_check = white_in_check.get();
    this->black_in_check = black_in_check.get();
}
board game_info::get_board_state()
{
    return this->board_state;
}
coordinates game_info::get_position()
{
    return this->position;
}
coordinates game_info::get_move()
{
    return this->move;
}
bool game_info::get_black_in_check()
{
    return this->black_in_check;
}
bool game_info::get_white_in_check()
{
    return this->white_in_check;
}
bool game_info::get_check_status(aliance::Enum a)
{
    if (a == aliance::WHITE)
    {
        return this->get_white_in_check();
    }
    else
    {
        return this->get_black_in_check();
    }
}
void game_info::set_board_state(board board_state)
{
    this->board_state = board_state;
}
void game_info::set_position(coordinates position)
{
    this->position = position;
}
void game_info::set_move(coordinates move)
{
    this->move = move;
}