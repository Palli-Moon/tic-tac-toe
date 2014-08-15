#include <ncurses.h>
#include "Board.h"

int main()
{
    
    Board b;
    b.draw_board();

    getch();
    return 0;
}
