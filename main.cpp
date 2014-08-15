#include <ncurses.h>

void draw_board()
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
}

int main()
{
    initscr();
    noecho();
    draw_board();
    getch();
    endwin();
    return 0;
}
