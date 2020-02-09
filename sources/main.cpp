#include <iostream>

#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/command_parser.h"
#include "../headers/command_executer.h"
#include "../headers/randomizer.h"

Map gameMap;
Player player;
Room* room;
std::string commandStr;
Command command;
std::string result;

int main()
{
    seedRand(0);
    command.code = START;
    result = executeCommand(command, player, room, gameMap);
    std::cout << result << std::endl;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, commandStr);
        command = parseCommand(commandStr);
        result = executeCommand(command, player, room, gameMap);
        std::cout << result << std::endl;
    }
    return 0;
}
