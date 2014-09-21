#ifndef PLAYER_H_
#define PLAYER_H_

#include <ncurses.h>

// Forward declaration
class Board;

class Player
{
public:
    explicit Player(Board *b); // 1 arg constructors should be explicit
    void get_command();

    int get_player_num() { return player_num; }
    char get_player_mark() { return player_mark; }

private:
    int player_num;
    char player_mark;

    Board *board;
    static int instances;
};

#endif  // PLAYER_H_
