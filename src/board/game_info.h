#include "coordinates.h"
#include "board.h"

class game_info
{
private:
    board board_state;
    coordinates position;
    coordinates move;
    bool black_in_check;
    bool white_in_check;

public:
    game_info(board board_state, coordinates position, coordinates move);
    game_info(){};
    ~game_info(){};
    board get_board_state();
    coordinates get_position();
    coordinates get_move();
    bool get_white_in_check();
    bool get_black_in_check();
    bool get_check_status(aliance::Enum a);
    void set_board_state(board board_state);
    void set_position(coordinates position);
    void set_move(coordinates move);
};
