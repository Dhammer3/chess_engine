#include <iostream>
//#include "piece.h"

#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{

    RenderWindow window(sf::VideoMode(450,450), "SFML works!");
	Texture board;
	board.loadFromFile("../images/board0.png");
	Sprite mBoard;
	mBoard.setTexture(board);
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
        window.display();
    }

    return 0;
}

