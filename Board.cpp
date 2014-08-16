#include "Board.h"

Board::Board():
curr_y(1),
curr_x(2),
HOR_MOVE_SPACES(4),
VER_MOVE_SPACES(2)
{
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
    move(1, 2);
    refresh();
}

void Board::move_cursor(direction dir)
{
    switch (dir)
    {
        case LEFT:
            curr_x -= HOR_MOVE_SPACES;
            break;
        case RIGHT:
            curr_x += HOR_MOVE_SPACES;
            break;
        case UP:
            curr_y -= VER_MOVE_SPACES;
            break;
        case DOWN:
            curr_y += VER_MOVE_SPACES;
            break;
        default:
            break;
    }
    move(curr_y, curr_x);
    refresh();
}
