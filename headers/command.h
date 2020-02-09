#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <vector>

#define UNKNOWN 0
#define START 1
#define WALK 2 // relative direction
#define TURN 3 // relative direction
#define LOOK_AROUND 4

struct Command
{
    int code = UNKNOWN;
    std::vector<int> args;
};

#endif // COMMAND_H_INCLUDED
