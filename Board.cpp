#include "Board.h"
#include "Player.h"
#include "Status.h"

Board::Board():
player_turn(1),
Y_OFFSET(1),
X_OFFSET(2),
HOR_MOVE_SPACES(4),
VER_MOVE_SPACES(2),
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
    initscr();
    noecho();
    cbreak();
    draw_board();
}

Board::~Board()
{
    endwin();
}

void Board::start_game_loop()
{
    Player P1(this);
    Player P2(this);
    Status St(this);

    while (true)
    {
        St.print_status();
        if (num_of_marks > 8) return;
        player_turn == 1 ? P1.get_command() : P2.get_command();
    }
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

int Board::check_if_win()
{
    for (int i = 0; i < 3; i++)
    {
        if (marks[0][i] == marks[1][i] &&
            marks[1][i] == marks[2][i]) return marks[0][i];
        if (marks[i][0] == marks[i][1] &&
            marks[i][1] == marks[i][2]) return marks[i][0];
    } 
    if (marks[0][0] == marks[1][1] &&
        marks[1][1] == marks[2][2]) return marks[0][0];
    if (marks[0][2] == marks[1][1] &&
        marks[1][1] == marks[0][2]) return marks[0][2];
    return 0;
}

void Board::return_cursor()
{
    move((curr_y * VER_MOVE_SPACES) + Y_OFFSET, 
         (curr_x * HOR_MOVE_SPACES) + X_OFFSET);
}
