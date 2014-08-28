#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include "Board.h"

class Player 
{
public:
    Player(Board &b);
    void get_command();
private:
    Board *board;
};

#endif
