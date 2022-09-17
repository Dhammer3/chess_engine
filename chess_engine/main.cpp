#include <iostream>
#include "king.h"
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{

    RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");
	Texture t0,t2;
	t0.loadFromFile("../images/board0.png");
	t2.loadFromFile("../images/wKing.png");
	Sprite mBoard, s1;
	mBoard.setTexture(t0);
	s1.setTexture(t2);

	int init_x, init_y, move_x,move_y;	
	bool flag;
	Vector2f scale = mBoard.getScale();
	king wKing(100, &s1, scale);
	wKing.move(1 ,3);
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
			if (event.type ==sf::Event::MouseButtonPressed) 
			{
				if(event.mouseButton.button==sf::Mouse::Left)
				{
				Vector2i mouse_pos = sf::Mouse::getPosition(window);
				init_x = static_cast<int>(mouse_pos.x/SQUARE_SIZE);
				init_y = static_cast<int>(mouse_pos.y/SQUARE_SIZE);
				
				//selected a piece
				if (init_x==wKing.x_pos&&init_y==wKing.y_pos)
				{
					flag=true;		
					std::cout<<"here1"<<std::endl;
				}
				}
			}
			if(event.type==Event::MouseButtonReleased)
			{
				Vector2i mouse_pos = sf::Mouse::getPosition(window);
                move_x = static_cast<int>(mouse_pos.x/SQUARE_SIZE);
                move_y = static_cast<int>(mouse_pos.y/SQUARE_SIZE);
				if(flag)
				{
				flag=!flag;
				wKing.move(move_x, move_y);
				}
					std::cout<<"here3"<<std::endl;
			}
        }
		
        window.clear();
        window.draw(mBoard);
        window.draw(*wKing.image);
        window.display();
    }

    return 0;
}

