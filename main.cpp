#include <ncurses.h>
#include "Board.h"

int main()
{
    
    Board b;
    b.move_cursor(LEFT);
    b.move_cursor(RIGHT);
    b.move_cursor(RIGHT);
    b.move_cursor(RIGHT);
    b.move_cursor(DOWN);
    b.move_cursor(DOWN);
    b.move_cursor(DOWN);
    b.move_cursor(DOWN);
    b.make_mark('x');
    b.move_cursor(LEFT);
    b.move_cursor(LEFT);

    getch();
    return 0;
}
