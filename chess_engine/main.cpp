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
	
	Vector2f scale = mBoard.getScale();
	king wKing(100, &s1, scale);
	wKing.move(1 ,1);
	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(mBoard);
        window.draw(*wKing.image);
        window.display();
    }

    return 0;
}

