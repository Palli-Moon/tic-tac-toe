#include <ncurses.h>
#include "Board.h"
#include "Player.h"

int main()
{
    
    Board b;
    b.start_game_loop();
    /*Player p(b);
    Player p2(b);
    while (true)
    {
        p.get_command();
        p2.get_command();
    }*/

    getch();
    return 0;
}
