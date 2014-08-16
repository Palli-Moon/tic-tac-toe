#include "Board.h"

Board::Board()
{
    initscr();
    noecho();
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
}
