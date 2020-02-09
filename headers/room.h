#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "directions.h"

struct Room
{
public:
    bool generated = false;
    int dirToSource = -1;
    int doors[NUM_DIRS] = {0, 0, 0, 0};
    bool light = true;
};

#endif // ROOM_H_INCLUDED
