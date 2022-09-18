#include "queen.h"
queen::queen(int value, sf::Sprite *s, sf::Vector2f v, aliance::Enum a):piece(value, s, v, a){}	
bool queen::move(board *game_board, int x_move, int y_move)
	{
		bool valid_move=piece::move(game_board,x_move, y_move); 
		if(!valid_move)
		{
			return false;
		}
		int x_vector = this->x_vector(x_move);
		int y_vector = this->y_vector(y_move);
		int diagonal_vector= this->diagonal_vector(x_move,y_move);

		if(x_vector!=0 || y_vector!=0)
		{
			//moving like a rook
			if(diagonal_vector==0)
			{
				valid_move = true;
			}
			//moving like a bishop
			
			std::cout<<diagonal_vector<<std::endl;
			// else
			// {
			// 	if(diagonal_vector!=(x_vector+y_vector))
			// 	{
			// 		valid_move=false;
			// 	}
			// 	else
			// 	{
			// 		valid_move=true;
			// 	}
			// }
		}
		return valid_move;
	}
