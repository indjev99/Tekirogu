#include "../headers/describer.h"
#include "../headers/dictionary.h"
#include <vector>

std::string describeRoom(const Room& room, const Player& player, int enter)
{
    std::string description = "";
    std::vector<int> doors;
    for (int d = 0; d < NUM_DIRS; ++d)
    {
        if (room.doors[turn(player.dir, d)]) doors.push_back(d);
    }
    if (enter)
    {
        switch (enter)
        {
        case ENTER:
            description += (*enterPat)(room.light) + " ";
            break;
        case APPEAR:
            description += (*appearPat)(room.light) + " ";
            break;
        }
    }
    if (!room.light)
    {
        description += (*blindPat)();
    }
    else
    {
        description += (*doorsPat)(doors);
    }
    return description;
}
