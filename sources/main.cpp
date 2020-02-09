#include <iostream>

#include "../headers/map.h"
#include "../headers/player.h"
#include "../headers/describer.h"
#include "../headers/command_parser.h"
#include "../headers/randomizer.h"

Map playMap;

int main()
{
    seedRand(0);
    Player player;
    std::string commandStr;
    const Room* room = &playMap.room(player.x, player.y);
    std::cout << describeRoom(*room, player, APPEAR) << std::endl;
    while (true)
    {
        std::getline(std::cin, commandStr);
        Command command = parseCommand(commandStr);
        room = &playMap.room(player.x, player.y);
        std::cout << describeRoom(*room, player, ENTER) << std::endl;
    }
    return 0;
}
