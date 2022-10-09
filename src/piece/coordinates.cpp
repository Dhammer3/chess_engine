#include "coordinates.h"

coordinates::coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

int coordinates::get_x()
{
    return this->x;
}
int coordinates::get_y()
{
    return this->y;
}
void coordinates::set_x(int x)
{
    this->x = x;
}
void coordinates::set_y(int y)
{
    this->y = y;
}

void coordinates::set(int x, int y)
{
    this->set_x(x);
    this->set_y(y);
}
