#ifndef DIRECTIONS_H_INCLUDED
#define DIRECTIONS_H_INCLUDED

#define NUM_DIRS 4

#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3

#define FORWARD 0
#define LEFT 1
#define BACK 2
#define RIGHT 3

#define ABSOLUTE 0
#define RELATIVE 1

int turn(int direction, int turnDirection);
int turnLeft(int direction);
int turnRight(int direction);
int turnBack(int direction);
void moveInDir(int direction, int& x, int& y);

#endif // DIRECTIONS_H_INCLUDED
