#include "board.h"
#include <thread>
#include <future>
board::board(std::vector<piece *> pieces, sf::RenderWindow &window, sf::Sprite *image)
{
    this->set_board(pieces);
    this->window = &window;
    this->board_image = image;
    this->pieces = pieces;
};
board::board(std::vector<piece *> pieces)
{
    this->set_board(pieces);
    this->pieces = pieces;
};

void board::clear_board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            this->game_board[i][j] = NULL;
        }
    }
}
void board::set_board(std::vector<piece *> pieces)
{
    this->clear_board();

    for (int i = 0; i < pieces.size(); i++)
    {
        piece *p = pieces[i];
        this->game_board[p->x_pos][p->y_pos] = p;
    }
}
bool board::piece_in_location(int x, int y)
{
    return this->game_board[x][y] != NULL;
}
piece *board::get_piece(int x, int y)
{
    if (piece_in_location(x, y))
    {
        return this->game_board[x][y];
    }
}
#include <thread>
#include <future>
bool board::capturing_own_piece(aliance::Enum a, int x, int y)
{
    if (piece_in_location(x, y))
    {
        return this->game_board[x][y]->aliance == a;
    }
    return false;
}
bool board::capturing_king(int x, int y)
{
    if (piece_in_location(x, y))
    {
        return this->game_board[x][y]->piece_type == piece_type::KING;
    }
    return false;
}

void board::draw_board(std::vector<piece *> pieces)
{
    this->set_board(pieces);

    this->window->clear();

    this->window->draw(*this->board_image);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->game_board[i][j])
            {
                piece *p = game_board[i][j];

                this->window->draw(*p->image);
            }
        }
    }

    this->window->display();
}
void board::remove_piece(piece *p)
{
    this->pieces.erase(find(this->pieces.begin(), this->pieces.end(), p));
    this->set_board(pieces);
}
std::vector<int> board::get_king_pos(aliance::Enum a)
{
    std::vector<int> ret;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->game_board[i][j])
            {
                piece *p = game_board[i][j];
                if (p->aliance == a && p->piece_type == piece_type::Enum::KING)
                {
                    // x
                    ret.push_back(i);
                    // y
                    ret.push_back(j);
                }
            }
        }
    }
    return ret;
}
// returns true if aliance is in checkmate
bool board::checkmate(aliance::Enum a)
{
    int split_size = 4;
    // std::vector<std::thread> threads(split_size);

    bool checkmate = false;
    int exec_count = 0;
    piece *p = new piece();
    std::size_t const split = this->pieces.size() / split_size;

    // split the pieces vector into split_size sized smaller vectors to avoid segmentation fault
    for (int n = 0; n < split_size - 1; n++)
    {
        std::vector<piece *> split_pieces(this->pieces.begin() + n * split, this->pieces.begin() + (n + 1) * split);
        // checkmate = std::thread(checkmate_helper, split_pieces, a);
        // std::thread t1 = std::thread(&board::checkmate_helper, this, split_pieces, a);
        auto chkmt = std::async(&board::checkmate_helper, this, split_pieces, a);
        if (chkmt.get())
        {
            return true;
        }
    }

    return checkmate;
}

bool board::checkmate_helper(std::vector<piece *> pieces, aliance::Enum a)
{
    // std::cout << "------launching thread..." << std::endl;
    int exec_count = 0;
    bool checkmate = false;

    piece *p = new piece();
    std::vector<int> king_pos = this->get_king_pos(a);
    bool null_king_pos = king_pos.empty();
    int &king_x = king_pos[0];
    int &king_y = king_pos[1];
    p = this->game_board[king_x][king_y];

    for (int i = 0; i < pieces.size(); i++)
    {
        p = pieces[i];
        if (p->aliance == a)
        {
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    auto can_move = std::async(&piece::move, p, this, x, y);
                    // std::cout << "****finished thread..." << std::endl;
                    // std::cout << "------------------------------" << std::endl;

                    return can_move.get();
                }
            }
        }
    }

    return checkmate;
}