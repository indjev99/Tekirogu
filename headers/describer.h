#ifndef DESCRIBER_H_INCLUDED
#define DESCRIBER_H_INCLUDED

#include "room.h"
#include "player.h"
#include <string>

#define STAY 0
#define ENTER 1
#define APPEAR 2

std::string describeRoom(const Room& room, const Player& player, int enter);

#endif // DESCRIBER_H_INCLUDED
