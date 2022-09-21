#include <iostream>
#include "king.h"
#include "queen.h"
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{

	RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");
	Texture t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13;

	t0.loadFromFile("../images/board0.png");

	t1.loadFromFile("../images/wKing.png");
	t2.loadFromFile("../images/bKing.png");
	t3.loadFromFile("../images/wQueen.png");
	t4.loadFromFile("../images/bQueen.png");
	t5.loadFromFile("../images/wPawn.png");
	t6.loadFromFile("../images/bPawn.png");
	t7.loadFromFile("../images/wBishop.png");
	t9.loadFromFile("../images/bBishop.png");
	t10.loadFromFile("../images/wRook.png");
	t11.loadFromFile("../images/bRook.png");
	t12.loadFromFile("../images/wKnight.png");
	t13.loadFromFile("../images/bKnight.png");

	Sprite mBoard, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13;
	mBoard.setTexture(t0);

	s1.setTexture(t1);
	s2.setTexture(t2);

	s3.setTexture(t4);

	int init_x, init_y, move_x, move_y, index;
	bool flag;
	Vector2f scale = mBoard.getScale();
	king wKing(100, &s1, scale, aliance::WHITE);
	king bKing(100, &s2, scale, aliance::BLACK);

	queen bQueen(10, &s3, scale, aliance::BLACK);
	wKing.set_position(4, 7);
	bKing.set_position(1, 7);

	bQueen.set_position(0, 0);

	std::vector<piece *> pieces;
	pieces.push_back(&wKing);
	pieces.push_back(&bKing);
	pieces.push_back(&bQueen);
	board game_board(pieces, window, &mBoard);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					Vector2i mouse_pos = sf::Mouse::getPosition(window);
					init_x = static_cast<int>(mouse_pos.x / SQUARE_SIZE);
					init_y = static_cast<int>(mouse_pos.y / SQUARE_SIZE);

					// selected a piece
					for (int i = 0; i < pieces.size(); i++)
					{
						if (init_x == pieces[i]->x_pos && init_y == pieces[i]->y_pos)
						{
							flag = true;
							index = i;
						}
					}
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				Vector2i mouse_pos = sf::Mouse::getPosition(window);
				move_x = static_cast<int>(mouse_pos.x / SQUARE_SIZE);
				move_y = static_cast<int>(mouse_pos.y / SQUARE_SIZE);
				if (flag)
				{
					flag = !flag;
					if (pieces[index]->move(&game_board, move_x, move_y))
					{
						pieces[index]->set_position(move_x, move_y);
						pieces[index]->increment_move_counter();
					}
				}
			}
		}
		game_board.draw_board(pieces);
	}

	return 0;
}
