#include "unit_tests.h"
piece_factory pf;
void unit_tests::init()
{
    	sf::Texture t0;
	sf::Sprite mBoard;
	t0.loadFromFile("../images/board0.png");
	mBoard.setTexture(t0);
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Chesss!");

	sf::Vector2f scale = mBoard.getScale();
	 pf(scale);
    	std::vector<piece *> pieces = piece_factory.get_pieces();

	board game_board(pieces, window, &mBoard);
}
void unit_tests::run_all_tests()
{



}