#include <iostream>
#include "piece.h"
#include "board.h"

#include <SFML/Graphics.hpp>
using namespace sf;
//const int offset=2;
//const int square_size=56;
int main()
{

    RenderWindow window(sf::VideoMode(455,455), "SFML works!");
	Texture t1,t2;
	t1.loadFromFile("../images/board0.png");
	t2.loadFromFile("../images/wKing.png");
	Sprite mBoard, wKing;
	mBoard.setTexture(t1);
	wKing.setTexture(t2);
	Vector2f scale = mBoard.getScale();
    wKing.setScale(scale.x/20,scale.y/20);
	wKing.setPosition(2*square_size-offset,-2); 
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
        window.draw(wKing);
        window.display();
    }

    return 0;
}

