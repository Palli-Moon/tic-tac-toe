#include "Board.h"
#include "Player.h"
#include "Status.h"

Board::Board():
player_turn(1),
curr_y(0),
curr_x(0),
num_of_marks(0)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            marks[i][j] = 0;
        }
    }
    ncurses_init();
    draw_board();
}

Board::~Board()
{
    // close ncurses
    endwin();
}

int Board::check_if_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (marks[0][i] == marks[1][i] &&
            marks[1][i] == marks[2][i])
            if (marks[0][i] != 0) return marks[0][i];
        if (marks[i][0] == marks[i][1] &&
            marks[i][1] == marks[i][2])
            if (marks[i][0] != 0) return marks[i][0];
    }
    if (marks[0][0] == marks[1][1] &&
        marks[1][1] == marks[2][2])
        if (marks[0][0] != 0) return marks[0][0];
    if (marks[0][2] == marks[1][1] &&
        marks[1][1] == marks[2][0])
        if (marks[0][2] != 0) return marks[0][2];
    return 0;
}

void Board::start_game_loop()
{
    Player p1(this);
    Player p2(this);
    Status st(this);

    st.print_status();
    while (check_if_win() == 0 && num_of_marks < 9)
    {
        player_turn == 1 ? p1.get_command() : p2.get_command();
        st.print_status();
    }
}

void Board::move_cursor(Direction dir)
{
    switch (dir)
    {
        case LEFT:
            if (curr_x > 0) curr_x--;
            break;
        case RIGHT:
            if (curr_x < 2) curr_x++;
            break;
        case UP:
            if (curr_y > 0) curr_y--;
            break;
        case DOWN:
            if (curr_y < 2) curr_y++;
            break;
        default:
            break;
    }
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET,
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
    refresh();
}

bool Board::make_mark(Player *player, char mark)
{
    if (marks[curr_y][curr_x] != 0) return false;
    mvaddch((curr_y * VER_MOVE_SPACES) + Y_OFFSET,
            (curr_x * HOR_MOVE_SPACES) + X_OFFSET, player->mark);
    marks[curr_y][curr_x] = player->player_num;
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET,
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
    num_of_marks++;
    player->player_num == 1 ? player_turn = 2 : player_turn = 1;
    refresh();
    return true;
}

void Board::return_cursor()
{
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET,
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
}

void Board::ncurses_init()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
}

void Board::draw_board()
{
    for (int i = 1; i < 12; ++i)
    {
        mvaddch(2, i, ACS_HLINE);
        mvaddch(4, i, ACS_HLINE);
        if (i % 4 == 0)
        {
            mvaddch(1, i, ACS_VLINE);
            mvaddch(2, i, ACS_PLUS);
            mvaddch(3, i, ACS_VLINE);
            mvaddch(4, i, ACS_PLUS);
            mvaddch(5, i, ACS_VLINE);
        }
    }
    move(Y_OFFSET, X_OFFSET);
    refresh();
}
