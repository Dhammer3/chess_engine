#include <iostream>
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include "knight.h"
#include "piece_factory.h"

#include "unit_tests.h"
#include <SFML/Graphics.hpp>
int main()
{
	unit_tests a;
	a.run_tests();
	sf::Texture t0;
	sf::Sprite mBoard;
	t0.loadFromFile("../images/board0.png");
	mBoard.setTexture(t0);
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");

	sf::Vector2f scale = mBoard.getScale();
	piece_factory piece_factory(scale);

	int init_x, init_y, move_x, move_y, index;
	bool flag;

	std::vector<piece *> pieces = piece_factory.get_pieces();

	std::cout << pieces[0]->value << std::endl;
	window.draw(mBoard);
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
					sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
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
			if (event.type == sf::Event::MouseButtonReleased)
			{
				sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
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
