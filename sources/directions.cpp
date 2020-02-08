#include "../headers/directions.h"

int turnRight(int direction)
{
    return (direction + 1) % NUM_DIRS;
}

int turnLeft(int direction)
{
    return (direction + 3) % NUM_DIRS;
}

int turnBack(int direction)
{
    return (direction + 2) % NUM_DIRS;
}

void moveInDir(int direction, int& x, int &y)
{
    switch (direction)
    {
    case NORTH:
        ++y;
        return;
    case WEST:
        --x;
        return;
    case SOUTH:
        --y;
        return;
    case EAST:
        ++x;
        return;
    }
}
