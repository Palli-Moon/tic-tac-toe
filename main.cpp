#include <ncurses.h>
#include "Board.h"
#include "Player.h"

int main()
{
    
    Board b;
    b.start_game_loop();

    getch();
    return 0;
}
