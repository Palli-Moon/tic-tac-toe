#include "Status.h"

Status::Status(Board *b):
X_OFFSET(0),
Y_OFFSET(0)
{
    board = b;
}

void Status::print_status()
{
    mvprintw(Y_OFFSET, X_OFFSET, "assfag");
    board->return_cursor();
    refresh();
}
