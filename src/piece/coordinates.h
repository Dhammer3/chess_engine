#if !defined(__COORDINATES_H__)
#define __COORDINATES_H__
class coordinates
{
protected:
    int x, y;

public:
    coordinates(){};
    coordinates(int x, int y);
    ~coordinates(){};
    int get_x();
    int get_y();
    void set(int x, int y);
    void set_x(int x);
    void set_y(int y);
};
#endif