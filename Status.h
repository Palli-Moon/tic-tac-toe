#ifndef STATUS_H
#define STATUS_H

#include <ncurses.h>

class Status
{
public:
    Status();
    void print_status();
private:
    int const X_OFFSET;
    int const Y_OFFSET;
};

#endif
