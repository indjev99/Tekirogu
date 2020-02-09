#ifndef COMMAND_EXECUTER_H_INCLUDED
#define COMMAND_EXECUTER_H_INCLUDED

#include "command.h"
#include "room.h"
#include "player.h"
#include "map.h"

std::string executeCommand(const Command& command, Player& player, Room*& room, Map& gameMap);

#endif // COMMAND_EXECUTER_H_INCLUDED
