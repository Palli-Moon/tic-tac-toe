#include "Status.h"
#include "Board.h"

Status::Status(Board *b)
{
    board = b;
}

void Status::print_status()
{
    int winner = board->check_if_win(); 
    if (winner != 0)
    {
        mvprintw(Y_OFFSET, X_OFFSET, "Player %i won", winner); 
    }else{
        mvprintw(Y_OFFSET, X_OFFSET, "Player: %i", board->get_player_turn());
    }
    board->return_cursor();
    refresh();
}
