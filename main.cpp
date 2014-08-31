#include <ncurses.h>
#include "Board.h"
#include "Player.h"

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
    b.move_cursor(UP);
    b.move_cursor(LEFT);
    b.make_mark('o');
    Player p(b);
    while (true) p.get_command();

    getch();
    return 0;
}
