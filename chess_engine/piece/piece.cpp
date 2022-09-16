#include "piece.h"
piece::piece(int value, sf::Sprite *image, sf::Vector2f scale)
{
this->value=value;
this->image=image;
this->image->setScale(scale.x/20, scale.y/20);
}
void piece::set_position(int x, int y)
{
	this->x_pos=x;
	this->y_pos=y;
}
