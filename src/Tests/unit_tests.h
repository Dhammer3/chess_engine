#include "piece_factory.h"
#include "coordinates.h"
#include "../board/board.h"
#include <SFML/Graphics.hpp>
class unit_tests
{
public:
#define IS_TRUE(x)                                                                    \
    {                                                                                 \
        if (!(x))                                                                     \
            std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
    };
    sf::Vector2f scale;
    piece_factory pf;
    board *game_board;

    unit_tests(){};
    unit_tests(piece_factory pf);
    void reset_board();
    void put_other_player_in_check();
    void put_self_in_check();
    void check();
    void run_all_tests();
};