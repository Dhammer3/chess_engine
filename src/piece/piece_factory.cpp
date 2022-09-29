#include "piece_factory.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "pawn.h"
#include "knight.h"
piece_factory::piece_factory(sf::Vector2f scale)
{
    this->scale = scale;
    std::vector<piece *> pieces;

    piece *bRook = new rook();
    piece *bRook2 = new rook();
    piece *bKnight = new knight();
    piece *bKnight2 = new knight();
    piece *bBishop = new bishop();
    piece *bBishop2 = new bishop();
    piece *bQueen = new queen();
    piece *bKing = new king();

    piece *wRook = new rook();
    piece *wRook2 = new rook();
    piece *wKnight = new knight();
    piece *wKnight2 = new knight();
    piece *wBishop = new bishop();
    piece *wBishop2 = new bishop();
    piece *wQueen = new queen();
    piece *wKing = new king();

    piece *bPawn0 = new pawn();
    piece *bPawn1 = new pawn();
    piece *bPawn2 = new pawn();
    piece *bPawn3 = new pawn();
    piece *bPawn4 = new pawn();
    piece *bPawn5 = new pawn();
    piece *bPawn6 = new pawn();
    piece *bPawn7 = new pawn();

    piece *wPawn0 = new pawn();
    piece *wPawn1 = new pawn();
    piece *wPawn2 = new pawn();
    piece *wPawn3 = new pawn();
    piece *wPawn4 = new pawn();
    piece *wPawn5 = new pawn();
    piece *wPawn6 = new pawn();
    piece *wPawn7 = new pawn();

    bRook = this->make_piece(aliance::BLACK, piece_type::ROOK);
    bRook2 = this->make_piece(aliance::BLACK, piece_type::ROOK);

    bKnight = this->make_piece(aliance::BLACK, piece_type::KNIGHT);
    bKnight2 = this->make_piece(aliance::BLACK, piece_type::KNIGHT);

    bBishop = this->make_piece(aliance::BLACK, piece_type::BISHOP);
    bBishop2 = this->make_piece(aliance::BLACK, piece_type::BISHOP);

    bQueen = this->make_piece(aliance::BLACK, piece_type::QUEEN);
    bKing = this->make_piece(aliance::BLACK, piece_type::KING);

    wRook = this->make_piece(aliance::WHITE, piece_type::ROOK);
    wRook2 = this->make_piece(aliance::WHITE, piece_type::ROOK);

    wKnight = this->make_piece(aliance::WHITE, piece_type::KNIGHT);
    wKnight2 = this->make_piece(aliance::WHITE, piece_type::KNIGHT);

    wBishop = this->make_piece(aliance::WHITE, piece_type::BISHOP);
    wBishop2 = this->make_piece(aliance::WHITE, piece_type::BISHOP);

    wQueen = this->make_piece(aliance::WHITE, piece_type::QUEEN);
    wKing = this->make_piece(aliance::WHITE, piece_type::KING);

    bPawn0 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn1 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn2 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn3 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn4 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn5 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn6 = this->make_piece(aliance::BLACK, piece_type::PAWN);
    bPawn7 = this->make_piece(aliance::BLACK, piece_type::PAWN);

    wPawn0 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn1 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn2 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn3 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn4 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn5 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn6 = this->make_piece(aliance::WHITE, piece_type::PAWN);
    wPawn7 = this->make_piece(aliance::WHITE, piece_type::PAWN);

    bPawn0->set_position(0, 1);
    bPawn1->set_position(1, 1);
    bPawn2->set_position(2, 1);
    bPawn3->set_position(3, 1);
    bPawn4->set_position(4, 1);
    bPawn5->set_position(5, 1);
    bPawn6->set_position(6, 1);
    bPawn7->set_position(7, 1);

    wPawn0->set_position(0, 6);
    wPawn1->set_position(1, 6);
    wPawn2->set_position(2, 6);
    wPawn3->set_position(3, 6);
    wPawn4->set_position(4, 6);
    wPawn5->set_position(5, 6);
    wPawn6->set_position(6, 6);
    wPawn7->set_position(7, 6);

    bRook->set_position(0, 0);
    bRook2->set_position(7, 0);
    bKnight->set_position(1, 0);
    bKnight2->set_position(6, 0);
    bBishop->set_position(2, 0);
    bBishop2->set_position(5, 0);
    bQueen->set_position(3, 0);
    bKing->set_position(4, 0);

    wRook->set_position(0, 7);
    wRook2->set_position(7, 7);
    wKnight->set_position(1, 7);
    wKnight2->set_position(6, 7);
    wBishop->set_position(2, 7);
    wBishop2->set_position(5, 7);
    wQueen->set_position(3, 7);
    wKing->set_position(4, 7);

    pieces.push_back(bRook);
    pieces.push_back(bRook2);
    pieces.push_back(bKnight);
    pieces.push_back(bKnight2);
    pieces.push_back(bBishop);
    pieces.push_back(bBishop2);
    pieces.push_back(bQueen);
    pieces.push_back(bKing);

    pieces.push_back(wRook);
    pieces.push_back(wRook2);
    pieces.push_back(wKnight);
    pieces.push_back(wKnight2);
    pieces.push_back(wBishop);
    pieces.push_back(wBishop2);
    pieces.push_back(wQueen);
    pieces.push_back(wKing);

    pieces.push_back(bPawn0);
    pieces.push_back(bPawn1);
    pieces.push_back(bPawn2);
    pieces.push_back(bPawn3);
    pieces.push_back(bPawn4);
    pieces.push_back(bPawn5);
    pieces.push_back(bPawn6);
    pieces.push_back(bPawn7);
    pieces.push_back(wPawn0);
    pieces.push_back(wPawn1);
    pieces.push_back(wPawn2);
    pieces.push_back(wPawn3);
    pieces.push_back(wPawn4);
    pieces.push_back(wPawn5);
    pieces.push_back(wPawn6);
    pieces.push_back(wPawn7);

        std::cout << &pieces[0]->aliance << std::endl;

    this->pieces = pieces;
};
piece *piece_factory::make_piece(aliance::Enum aliance, piece_type::Enum piece_type)
{

    sf::Texture *t0 = new sf::Texture();
    sf::Sprite *s0 = new sf::Sprite();
    std::string path = "../images/";
    aliance == aliance::WHITE ? path += "w" : path += "b";

    switch (piece_type)
    {
    case piece_type::PAWN:
    {
        path += "Pawn.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new pawn(s0, this->scale, aliance);
        return ret;
    }
    case piece_type::ROOK:
    {
        path += "Rook.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new rook(s0, this->scale, aliance);
        return ret;
    }
    case piece_type::KNIGHT:
    {
        path += "Knight.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new knight(s0, this->scale, aliance);
        return ret;
    }
    case piece_type::BISHOP:
    {
        path += "Bishop.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new bishop(s0, this->scale, aliance);
        return ret;
    }
    case piece_type::QUEEN:
    {
        path += "Queen.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new queen(s0, this->scale, aliance);
        return ret;
    }
    case piece_type::KING:
    {
        path += "King.png";
        t0->loadFromFile(path);
        s0->setTexture(*t0);
        piece *ret = new king(s0, this->scale, aliance);
        return ret;
    }
    default:
        break;
    }
}
std::vector<piece *> piece_factory::get_pieces()
{
    return this->pieces;
};