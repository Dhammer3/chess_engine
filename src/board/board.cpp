#include "board.h"
board::board(std::vector<piece *> pieces, sf::RenderWindow &window, sf::Sprite *image)
{
    this->set_board(pieces);
    this->window = &window;
    this->board_image = image;
    // this->pieces
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
    return this->game_board[x][y] != 0;
}
bool board::capturing_own_piece(aliance::Enum a, int x, int y)
{
    if (piece_in_location(x, y))
    {
        return this->game_board[x][y]->aliance == a;
    }
    return false;
}
bool board::in_check(aliance::Enum a, int king_x, int king_y)
{

    static int recursion_counter = 0;
    if (recursion_counter == 0)
    {

        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (this->game_board[i][j])
                {
                    recursion_counter++;
                    piece *p = game_board[i][j];
                    if (p->move(this, king_x, king_y))
                    {
                        return true;
                    }
                }
            }
        }
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