#ifndef PLAYER_H_
#define PLAYER_H_

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

#endif  // PLAYER_H_
