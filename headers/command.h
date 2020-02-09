#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <vector>

#define UNKNOWN 0
#define WALK 1 // relative? direction
#define TURN 2 // relative? direction
#define LOOK_AROUND 3

struct Command
{
    int code = UNKNOWN;
    std::vector<int> args;
};

#endif // COMMAND_H_INCLUDED
