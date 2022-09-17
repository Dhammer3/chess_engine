#include "piece.h"
piece::piece(int value, sf::Sprite *image, sf::Vector2f scale, aliance::Enum a)
{
this->value=value;
this->image=image;
this->image->setScale(scale.x/20, scale.y/20);
this->x_pos=0;
this->y_pos=0;
this->move_counter=0;
this->aliance=a;
}
void piece::set_position(int x, int y)
{
	this->image->setPosition(x*SQUARE_SIZE+OFFSET, y*SQUARE_SIZE+OFFSET);
	this->x_pos=x;
	this->y_pos=y;
}

void piece::increment_move_counter()
{
	this->move_counter+=1;
}
bool piece::in_check(std::vector<piece*> pieces, int kingX, int kingY)
{
	bool can_move_to_king_pos=false;
	for (int i=0; i<pieces.size(); i++)
	{
        piece *p = pieces[i];
		if (enemy_piece(p))
		{
			can_move_to_king_pos= p->move(kingX, kingY);
			if(can_move_to_king_pos)
			{
				return true;
				std::cout << "king is in check"<<std::endl;
			}
		}
	}
	return can_move_to_king_pos;
}
 bool piece::enemy_piece(piece *p)
 {
 	return this->aliance!=p->aliance;
 }
