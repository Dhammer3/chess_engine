#include <iostream>
#include "piece_factory.h"

#include <SFML/Graphics.hpp>
int main()
{
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
					for (int i = 0; i < game_board.pieces.size(); i++)
					{
						if (init_x == game_board.pieces[i]->x_pos && init_y == game_board.pieces[i]->y_pos)
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
					if (game_board.pieces[index]->move(&game_board, move_x, move_y))
					{
						if (game_board.game_board[move_x][move_y])
						{
							//

							game_board.pieces[index]->set_position(move_x, move_y);

							game_board.pieces[index]->increment_move_counter();
							game_board.remove_piece(game_board.game_board[move_x][move_y]);
						}
						else
						{
							game_board.pieces[index]->set_position(move_x, move_y);
							game_board.pieces[index]->increment_move_counter();
						}

						// if capturing a piece
					}
				}
			}
			game_board.draw_board(game_board.pieces);
		}
	}

	return 0;
}
