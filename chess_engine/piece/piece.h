#include <iostream>
#include <SFML/Graphics.hpp>
#include "../board/board.h"
class piece:sf::Sprite
{
        public:
				piece(int value, sf::Sprite *image, sf::Vector2f scale);
   				void move(int x_pos, int y_pos);
				int value;
				sf::Sprite *image;
			  			 
};


