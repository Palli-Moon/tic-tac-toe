#include <ncurses.h>
#include "Board.h"

int main()
{
    
    Board b;
    b.move_cursor(RIGHT);
    b.move_cursor(RIGHT);
    b.move_cursor(DOWN);
    b.move_cursor(DOWN);

    getch();
    return 0;
}
