#include "Status.h"
#include "Board.h"

Status::Status(Board *b)
{
    board = b;
}

void Status::print_status()
{
    mvprintw(Y_OFFSET, X_OFFSET, "Player: %i", board->player_turn);
    if (board->check_if_win() != 0)
    {
        mvprintw(Y_OFFSET + 2, X_OFFSET, "Player has won");
    }
    board->return_cursor();
    refresh();
}
