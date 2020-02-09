#include "../headers/command_executer.h"
#include "../headers/directions.h"
#include "../headers/describer.h"
#include "../headers/randomizer.h"

std::string executeStart(Player& player, Room*& room, Map& gameMap)
{
    player.dir = randInt(NUM_DIRS);
    room = &gameMap.room(player.x, player.y);
    return describeRoom(*room, player, APPEAR);
}

int handleTurn(int rel, int dir, Player& player)
{
    if (rel == RELATIVE)
        return dir;
    else if (player.compass == true)
        return (NUM_DIRS + dir - player.dir) % NUM_DIRS;
    return -1;
}

std::string executeWalk(int rel, int dir, Player& player, Room*& room, Map& gameMap)
{
    int turnAmt = handleTurn(rel, dir, player);
    if (turnAmt == -1)
        return describeUnknownAbsolute(dir);

    int newDir = turn(player.dir, turnAmt);
    if (!room->doors[newDir])
        return describeNoDoor(turnAmt);

    player.dir = newDir;
    moveInDir(player.dir, player.x, player.y);
    room = &gameMap.room(player.x, player.y);
    return describeRoom(*room, player, ENTER);
}

std::string executeTurn(int rel, int dir, Player& player)
{
    int turnAmt = handleTurn(rel, dir, player);
    if (turnAmt == -1)
        return describeUnknownAbsolute(dir);

    player.dir = turn(player.dir, turnAmt);
    return describeTurn(turnAmt);
}

std::string executeLookAround(Player& player, Room*& room)
{
    return describeRoom(*room, player, STAY);
}

std::string executeCommand(const Command& command, Player& player, Room*& room, Map& gameMap)
{
    switch (command.code)
    {
    case UNKNOWN:
        return describeUnknownCommand();
    case START:
        return executeStart(player, room, gameMap);
    case WALK:
        return executeWalk(command.args[0], command.args[1], player, room, gameMap);
    case TURN:
        return executeTurn(command.args[0], command.args[1], player);
    case LOOK_AROUND:
        return executeLookAround(player, room);
    }
    return "ERROR";
}
