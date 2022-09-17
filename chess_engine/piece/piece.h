# if !defined(__PIECE_H__)
#define __PIECE_H__
#include "aliance.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../board/board.h"
 class piece:sf::Sprite
{
        public:
				piece(int value, sf::Sprite *image, sf::Vector2f scale, aliance::Enum a);
   				virtual bool move(int x_pos, int y_pos)=0;
				int value;
				int x_pos, y_pos,move_counter;
				sf::Sprite *image;
				aliance::Enum aliance;
				void set_position(int x, int y);
				void increment_move_counter();
				bool in_check(std::vector<piece> pieces, int kingX, int kingY);
				bool enemy_piece(piece *p);
	  			 
};
# endif

