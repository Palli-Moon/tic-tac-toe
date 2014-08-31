#include "Player.h"

int Player::instances = 0;

Player::Player(Board &b)
{
    board = &b;
    instances++;
    player_num = instances;
}

void Player::get_command()
{
    keypad(stdscr, true);
    wchar_t ch;
    ch = getch();
    switch (ch)
    {
        case KEY_LEFT:
        case 'a':
            board->move_cursor(LEFT);
            break;
        case KEY_RIGHT:
        case 'd':
            board->move_cursor(RIGHT);
            break;
        case KEY_UP:
        case 'w':
            board->move_cursor(UP);
            break;
        case KEY_DOWN:
        case 's':
            board->move_cursor(DOWN);
            break;
        case KEY_ENTER:
        case ' ':
            board->make_mark(1);
            break;
    }
}

