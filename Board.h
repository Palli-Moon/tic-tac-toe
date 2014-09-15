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
    void start_game_loop();
    void move_cursor(Direction dir);
    bool make_mark(Player *player, char mark);
    void return_cursor();
    int check_if_win();

    int player_turn;
private:
    void ncurses_init();
    void draw_board();

    int const Y_OFFSET;
    int const X_OFFSET;
    int const HOR_MOVE_SPACES;
    int const VER_MOVE_SPACES;
    int curr_y, curr_x;
    int num_of_marks;
    int marks[3][3];
};

#endif  // BOARD_H_
