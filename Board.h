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
    void move_cursor(direction dir);
private:
    void draw_board();

    int curr_y, curr_x;
};

#endif
