#include <iostream>

#include "../headers/map.h"
#include "../headers/dictionary.h"
#include "../headers/directions.h"
#include "../headers/randomizer.h"
#include "../headers/player.h"
#include "../headers/describer.h"

Map playMap;

int main()
{
    seedRand(0);
    Player player;
    std::string command;
    while (true)
    {
        const Room& room = playMap.room(player.x, player.y);
        std::cout << describeRoom(room, player) << std::endl;
        //std::getline(std::cin, command);
        std::cin >> player.x >> player.y >> player.dir;
    }
    return 0;
}
