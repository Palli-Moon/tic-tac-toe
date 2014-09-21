#ifndef STATUS_H_
#define STATUS_H_

#include <ncurses.h>

class Board;

class Status
{
public:
    explicit Status(Board *b);
    void print_status();

private:
    static const int Y_OFFSET = 1;
    static const int X_OFFSET = 15;

    Board *board;
};

#endif  // STATUS_H_
