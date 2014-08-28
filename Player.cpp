#include "Player.h"

Player::Player(Board &b)
{
    board = &b;
}

void Player::get_command()
{
    wchar_t ch;
    ch = getch();
    switch (ch)
    {
        case 'a':
            board->move_cursor(LEFT);
            break;
        case 'd':
            board->move_cursor(RIGHT);
            break;
        case 'w':
            board->move_cursor(UP);
            break;
        case 's':
            board->move_cursor(DOWN);
            break;
    }
    refresh();
}
