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

    int const Y_OFFSET;
    int const X_OFFSET;
    int const HOR_MOVE_SPACES;
    int const VER_MOVE_SPACES;
    int curr_y, curr_x;
    int marks[3][3];
};

#endif
