#include "../headers/command_parser.h"
#include "../headers/command_dictionary.h"
#include <sstream>

#define COMMAND 0
#define DIRECTION 1
#define AROUND 2
#define DONE 3
#define FAIL 4

Command parseCommand(std::string commandStr)
{
    for (char& c : commandStr)
    {
        if (!isalpha(c)) c = ' ';
    }
    Command command;
    std::string word;
    std::stringstream commandStream(commandStr);

    int state = COMMAND;
    while (state != DONE && state != FAIL && getline(commandStream, word, ' '))
    {
        switch (state)
        {
        case COMMAND:
            if (walkCW.match(word))
            {
                command.code = WALK;
                state = DIRECTION;
            }
            else if (turnCW.match(word))
            {
                command.code = TURN;
                state = DIRECTION;
            }
            else if (lookCW.match(word))
            {
                command.code = LOOK_AROUND;
                state = AROUND;
            }
            break;
        case DIRECTION:
            for (int d = 0; d < NUM_DIRS; ++d)
            {
                if (relDirCW[d].match(word))
                {
                    command.args.push_back(RELATIVE);
                    command.args.push_back(d);
                    state = DONE;
                }
                else if (absDirCW[d].match(word))
                {
                    command.args.push_back(ABSOLUTE);
                    command.args.push_back(d);
                    state = DONE;
                }
            }
            break;
        case AROUND:
            if (aroundDirCW.match(word))
            {
                state = DONE;
            }
            break;
        }
    }
    if (state != DONE) command.code = UNKNOWN;
    return command;
}
