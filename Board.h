#ifndef BOARD_H_
#define BOARD_H_

#include <ncurses.h>

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Player;

class Board
{
public:
    Board();
    ~Board();
    int check_if_win();
    void start_game_loop();
    void move_cursor(Direction dir);
    bool make_mark(Player *player, char mark);
    void return_cursor();

    int get_player_turn() { return player_turn; }

private:
    static const int Y_OFFSET = 1;
    static const int X_OFFSET = 2;
    static const int HOR_MOVE_SPACES = 4;
    static const int VER_MOVE_SPACES = 2;

    void ncurses_init();
    void draw_board();

    int player_turn;
    int curr_y, curr_x;
    int num_of_marks;
    int marks[3][3];
};

#endif  // BOARD_H_
