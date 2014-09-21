#include "Status.h"
#include "Board.h"

Status::Status(Board *b)
{
    board = b;
}

void Status::print_status()
{
    if (board->check_if_win() != 0)
    {
        mvprintw(Y_OFFSET, X_OFFSET, "Player %i won", board->get_player_turn());
    }else{
        mvprintw(Y_OFFSET, X_OFFSET, "Player: %i", board->get_player_turn());
    }
    board->return_cursor();
    refresh();
}
