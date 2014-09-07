#ifndef STATUS_H
#define STATUS_H

#include <ncurses.h>

class Board;

class Status
{
public:
    Status(Board *b);
    void print_status();
private:
    Board *board;

    int const Y_OFFSET;
    int const X_OFFSET;
};

#endif