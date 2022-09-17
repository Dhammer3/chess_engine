#include "king.h"
king::king(int value, sf::Sprite *s, sf::Vector2f v ,aliance::Enum a):piece(value, s, v, a){}	
bool king::move( int x_pos, int y_pos)
	{
		bool valid_move=true;
		int diff_x= this->x_pos-x_pos;
		int diff_y= this->y_pos-y_pos;
		int x_squared= diff_x*diff_x;
		int y_squared= diff_y*diff_y;
		if (x_squared+y_squared>2)//or board at move location friendly or putting self in check
		{
			valid_move=!valid_move;
		}
		return valid_move;
		
		//this->image->setPosition(x_pos*SQUARE_SIZE+OFFSET, y_pos*SQUARE_SIZE+OFFSET);
	}
