#include "piece.h"
#include <cmath>
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
//no piece can capture its own piece or put itself in check
bool piece::move(board *game_board, int x_pos, int y_pos)
{
	bool valid_move=true; 
	if(game_board->friendly_piece_in_location(this->aliance, x_pos, y_pos))
	{
		valid_move=false;
	}
	//or putting self in check
	return valid_move;

}
void piece::set_position( int x, int y)
{
	this->image->setPosition(x*SQUARE_SIZE+OFFSET, y*SQUARE_SIZE+OFFSET);
	this->x_pos=x;
	this->y_pos=y;
}
void piece::increment_move_counter()
{
	this->move_counter+=1;
}
// bool piece::in_check(std::vector<piece*> pieces, int kingX, int kingY)
// {
// 	bool can_move_to_king_pos=false;
// 	for (int i=0; i<pieces.size(); i++)
// 	{
//         piece *p = pieces[i];
// 		if (enemy_piece(p))
// 		{
// 			can_move_to_king_pos= p->move(kingX, kingY);
// 			if(can_move_to_king_pos)
// 			{
// 				return true;
// 				std::cout << "king is in check"<<std::endl;
// 			}
// 		}
// 	}
// 	return can_move_to_king_pos;
// }
bool piece::enemy_piece(piece *p)
 {
 	return this->aliance!=p->aliance;
 }
int piece::x_vector(int x_move)
{
	return this->x_pos-x_move;
}
int piece::y_vector(int y_move)
{
	return this->y_pos-y_move;
}
int piece::diagonal_vector(int x_move, int y_move)
{
	int x = this->x_vector(x_move);
	int y = this->y_vector(y_move);
	std::cout<<"y "<<y<<std::endl;
	std::cout<<"x "<<x<<std::endl;

	if (x==0||y==0)
	{
		return 0;
	}
	int move_vector = sqrt(x*x + y*y);
	return move_vector;
}