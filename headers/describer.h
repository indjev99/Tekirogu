#ifndef DESCRIBER_H_INCLUDED
#define DESCRIBER_H_INCLUDED

#include "room.h"
#include "player.h"
#include <string>

std::string describeRoom(const Room& room, const Player& player, bool enter=true);

#endif // DESCRIBER_H_INCLUDED
