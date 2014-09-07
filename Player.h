#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

// Forward declaration
class Board;

class Player 
{
public:
    Player(Board *b);
    void get_command();

    int player_num;
    char mark;
private:
    Board *board;
    static int instances;
};

#endif
