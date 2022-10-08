#include <iostream>
#include "piece_factory.h"
#include "unit_tests.h"
#include <SFML/Graphics.hpp>
int main()
{
	sf::Texture t0;
	sf::Sprite mBoard;
	t0.loadFromFile("../images/board0.png");
	mBoard.setTexture(t0);
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");
	window.draw(mBoard);

	sf::Vector2f scale = mBoard.getScale();
	piece_factory pf(scale);
	piece_factory test_pf(scale);

	int init_x, init_y, move_x, move_y;
	bool selected_a_piece;
	piece *selected_piece;

	std::vector<piece *> pieces = pf.get_pieces();

	board gb(pieces, window, &mBoard);

	unit_tests ut(pf);
	ut.run_all_tests();
	gb.draw_board(gb.pieces);

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

					if (gb.piece_in_location(init_x, init_y))
					{
						selected_piece = gb.get_piece(init_x, init_y);
						selected_a_piece = true;
					}
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
				move_x = static_cast<int>(mouse_pos.x / SQUARE_SIZE);
				move_y = static_cast<int>(mouse_pos.y / SQUARE_SIZE);
				if (selected_a_piece)
				{
					selected_a_piece = false;
					if (selected_piece->move(&gb, move_x, move_y))
					{
						if (gb.game_board[move_x][move_y])
						{
							selected_piece->set_position(move_x, move_y);
							selected_piece->increment_move_counter();
							gb.remove_piece(gb.game_board[move_x][move_y]);
						}
						else
						{
							selected_piece->set_position(move_x, move_y);
							selected_piece->increment_move_counter();
						}
						// if (checkmate)
						// {
						// 	std::cout << "WHITE WINS!" << std::endl;
						// }
						// else
						// {
						// 	std::cout << "WHITE DIDNT WIN!" << std::endl;
						// }
					}
				}

				// checkmate = cp->checkmate(aliance::BLACK);

				board *cp = new board(gb.pieces);
				bool checkmate = cp->checkmate(aliance::BLACK);
				gb.draw_board(gb.pieces);
			}
		}
	}

	return 0;
}
