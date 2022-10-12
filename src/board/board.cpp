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
bool board::piece_in_location(coordinates move)
{
    return this->game_board[move.get_x()][move.get_y()] != NULL;
}
piece *board::get_piece(coordinates piece_loc)
{
    if (piece_in_location(piece_loc))
    {
        return this->game_board[piece_loc.get_x()][piece_loc.get_y()];
    }
}

bool board::capturing_own_piece(aliance::Enum a, coordinates move)
{
    if (piece_in_location(move))
    {
        return this->game_board[move.get_x()][move.get_y()]->aliance == a;
    }
    return false;
}
bool board::capturing_king(coordinates move)
{
    if (piece_in_location(move))
    {
        return this->game_board[move.get_x()][move.get_y()]->piece_type == piece_type::KING;
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
std::vector<piece *> board::get_enemy_pieces(aliance::Enum a)
{
    std::vector<piece *> enemy_pieces;
    for (int i = 0; i < this->pieces.size(); i++)
    {
        if (this->pieces[i]->aliance != a)
        {
            enemy_pieces.push_back(this->pieces[i]);
        }
    }
    return enemy_pieces;
}
bool board::in_check(aliance::Enum a)
{
    bool in_check = false;
    std::vector<int> king_pos = this->get_king_pos(a);
    int &king_x = king_pos[0];
    int &king_y = king_pos[1];
    coordinates king_position(king_x, king_y);
    board *game_board_copy = new board(*this);
    piece_factory *pf = new piece_factory();
    game_board_copy->game_board[king_x][king_y] = pf->make_piece(a, piece_type::PAWN);
    game_board_copy->set_board(game_board_copy->pieces);
    // std::vector<piece*> enemy_pieces= this->get_enemy_pieces(a);
    int split_size = 4;
    std::size_t const split = game_board_copy->pieces.size() / split_size;

    for (int n = 0; n < split_size - 1; n++)
    {
        std::vector<piece *> split_pieces(game_board_copy->pieces.begin() + n * split, game_board_copy->pieces.begin() + (n + 1) * split);
        // in_check = in_check_helper(split_pieces, a, king_position, game_board_copy);
        // auto chk = std::async(&board::in_check, this, a);

        auto chk = std::async(&board::in_check_helper, this, split_pieces, a, king_position, game_board_copy);
        if (chk.get())
        {
            return true;
        }
    }

    return in_check;
}
bool board::in_check_helper(std::vector<piece *> pieces, aliance::Enum a, coordinates king_position, board *game_board_copy)
{
    // std::cout << "------launching thread..." << std::endl;

    for (int i = 0; i < pieces.size(); i++)
    {
        if (pieces[i]->aliance != a)
        {
            if (pieces[i]->move(game_board_copy, king_position))
            {
                // std::cout << "------terminating thread..." << std::endl;

                return true;
            }
        }
    }
    // std::cout << "------terminating thread..." << std::endl;

    return false;
}

bool board::checkmate(aliance::Enum a)
{
    int split_size = 4;
    // std::vector<std::thread> threads(split_size);

    bool checkmate = false;
    piece *p = new piece();
    std::size_t const split = this->pieces.size() / split_size;

    // split the pieces vector into split_size sized smaller vectors to avoid segmentation fault
    for (int n = 0; n < split_size - 1; n++)
    {
        std::vector<piece *> split_pieces(this->pieces.begin() + n * split, this->pieces.begin() + (n + 1) * split);
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
                    coordinates move(x, y);
                    auto can_move = std::async(&piece::move, p, this, move);
                    return can_move.get();
                }
            }
        }
    }

    return checkmate;
}