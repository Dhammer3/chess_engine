#include <iostream>
#include "unit_tests.h"
#include "../piece/king.h"
#include "../piece/queen.h"
#include "../piece/bishop.h"
#include "../piece/rook.h"

#include <SFML/Graphics.hpp>
// Function to test
#define ASSERT_IS_TRUE(x)                                                                          \
    {                                                                                              \
        if (!(x))                                                                                  \
            std::cout << __FUNCTION__ << " ***FAILED UNIT TEST on line " << __LINE__ << std::endl; \
    }

// THE CHESS BOARD INDEXES
//  [00,10,20,30,40,50,60,70]
//  [01,11,21,31,41,51,61,71]
//  [02,12,22,32,42,52,62,72]
//  [03,13,23,33,43,53,63,73]
//  [04,14,24,34,44,54,64,74]
//  [05,15,25,35,45,55,65,75]
//  [06,16,26,36,46,56,66,76]
//  [07,17,27,37,47,57,67,77]
void unit_tests::run_tests()
{
    sf::Texture t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;
    sf::Sprite mBoard, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13;
    mBoard.setTexture(t0);

    sf::Vector2f scale = mBoard.getScale();
    king wKing(&s1, scale, aliance::WHITE);
    king bKing(&s2, scale, aliance::BLACK);

    queen wQueen(&s3, scale, aliance::WHITE);
    queen bQueen(&s4, scale, aliance::BLACK);
    bishop bBishop(&s5, scale, aliance::BLACK);
    rook wRook(&s6, scale, aliance::WHITE);

    wKing.set_position(4, 7);
    bKing.set_position(1, 7);

    bQueen.set_position(0, 0);
    bQueen.set_position(0, 1);
    bBishop.set_position(4, 0);
    wRook.set_position(6, 7);

    std::vector<piece *> pieces;
    pieces.push_back(&wKing);
    pieces.push_back(&bKing);
    pieces.push_back(&bQueen);
    pieces.push_back(&wQueen);
    pieces.push_back(&bBishop);
    pieces.push_back(&wRook);

    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");
    board game_board(pieces, window, &mBoard);

    // NOT VALID MOVES
    // put self in check
    ASSERT_IS_TRUE(!wKing.move(&game_board, 4, 5));
    // bishop moving like a rook
    ASSERT_IS_TRUE(!bBishop.move(&game_board, bBishop.x_pos + 1, bBishop.y_pos));
    ASSERT_IS_TRUE(!bBishop.move(&game_board, bBishop.x_pos, bBishop.y_pos + 1));

    // rook moving like a bishop
    ASSERT_IS_TRUE(!bBishop.move(&game_board, wRook.x_pos + 1, wRook.y_pos + 1));
    ASSERT_IS_TRUE(!bBishop.move(&game_board, wRook.x_pos + 1, wRook.y_pos + 1));

    // valid moves
    ASSERT_IS_TRUE(wKing.move(&game_board, 4, 6));
    ASSERT_IS_TRUE(wKing.move(&game_board, 3, 7));
    ASSERT_IS_TRUE(wKing.move(&game_board, 5, 7));
    ASSERT_IS_TRUE(bBishop.move(&game_board, 3, 1));
    ASSERT_IS_TRUE(wRook.move(&game_board, 5, 6));
}
