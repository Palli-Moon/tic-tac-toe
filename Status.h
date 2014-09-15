#ifndef STATUS_H_
#define STATUS_H_

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

#endif  // STATUS_H_
