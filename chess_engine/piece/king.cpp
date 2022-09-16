#include "king.h"
king::king(int value, sf::Sprite *s, sf::Vector2f v):piece(value, s, v){}	
void king::move( int x_pos, int y_pos)
	{
		int diff_x= this->x_pos-x_pos;
		int diff_y= this->y_pos-y_pos;
		if (diff_x-diff_y>2||diff_x-diff_y<-2)
		{
			//invalid move
			return;
		}	
		

		this->image->setPosition(x_pos*SQUARE_SIZE+OFFSET, y_pos*SQUARE_SIZE+OFFSET);
		this->set_position(x_pos, y_pos);
	}
