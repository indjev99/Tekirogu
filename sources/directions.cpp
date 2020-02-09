#include "../headers/directions.h"

int turn(int direction, int turnDirection)
{
    return (direction + turnDirection) % NUM_DIRS;
}
int turnLeft(int direction)
{
    return turn(direction, LEFT);
}
int turnRight(int direction)
{
    return turn(direction, RIGHT);
}
int turnBack(int direction)
{
    return turn(direction, BACK);
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
