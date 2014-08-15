#include <ncurses.h>
#include "Board.h"

int main()
{
    initscr();
    noecho();
    
    Board b;
    b.draw_board();

    getch();
    endwin();
    return 0;
}
