#include "Board.h"

Board::Board():
Y_OFFSET(1),
X_OFFSET(2),
HOR_MOVE_SPACES(4),
VER_MOVE_SPACES(2),
curr_y(0),
curr_x(0)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            marks[i][j] = 0;
        }
    }
    initscr();
    noecho();
    draw_board();
}

Board::~Board()
{
    endwin();
}

void Board::draw_board()
{
    for (int i = 1; i < 12; ++i)
    {
        mvaddch(2, i, '-');
        mvaddch(4, i, '-');
        if (i % 4 == 0)
        {
            mvaddch(1, i, '|');
            mvaddch(2, i, '+');
            mvaddch(3, i, '|');
            mvaddch(4, i, '+');
            mvaddch(5, i, '|');
        }
    }
    move(Y_OFFSET, X_OFFSET);
    refresh();
}

void Board::move_cursor(Direction dir)
{
    switch (dir)
    {
        case LEFT:
            if (curr_x > 0) curr_x--;
            break;
        case RIGHT:
            if (curr_x < 2) curr_x++;
            break;
        case UP:
            if (curr_y > 0) curr_y--;
            break;
        case DOWN:
            if (curr_y < 2) curr_y++;
            break;
        default:
            break;
    }
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET, 
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
    refresh();
}

void Board::make_mark(char mark)
{
    mvaddch((curr_y * VER_MOVE_SPACES) + Y_OFFSET, 
            (curr_x * HOR_MOVE_SPACES) + X_OFFSET, mark);
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET, 
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
    refresh();
}
