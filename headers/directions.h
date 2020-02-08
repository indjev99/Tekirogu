#ifndef DIRECTIONS_H_INCLUDED
#define DIRECTIONS_H_INCLUDED

#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3
#define NUM_DIRS 4

int turnRight(int direction);
int turnLeft(int direction);
int turnBack(int direction);
void moveInDir(int direction, int& x, int& y);

#endif // DIRECTIONS_H_INCLUDED