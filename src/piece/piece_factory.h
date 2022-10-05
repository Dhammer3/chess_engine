#include "piece.h"
#include <SFML/Graphics.hpp>
// This class builds the pieces
class piece_factory
{
public:
    piece_factory(){};
    piece_factory(sf::Vector2f scale);
    std::vector<piece *> get_pieces();
    sf::Vector2f scale;
    std::vector<piece *> pieces;

    piece *make_piece(aliance::Enum a, piece_type::Enum p);
};