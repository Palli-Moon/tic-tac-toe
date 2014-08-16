#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

enum direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Board
{
public:
    Board();
    ~Board();
    void draw_board();
    void move_cursor(direction dir);
};

#endif
