#include "Status.h"
#include "Board.h"

Status::Status(Board *b):
Y_OFFSET(1),
X_OFFSET(15)
{
    board = b;
}

void Status::print_status()
{
    mvprintw(Y_OFFSET, X_OFFSET, "Player: %i", board->player_turn);
    mvprintw(Y_OFFSET + 1, X_OFFSET, "");
    mvprintw(Y_OFFSET + 2, X_OFFSET, "");
    mvprintw(Y_OFFSET + 3, X_OFFSET, "");
    mvprintw(Y_OFFSET + 4, X_OFFSET, "");
    board->return_cursor();
    refresh();
}
