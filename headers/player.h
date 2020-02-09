#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Player
{
    int x = 0, y = 0;
    int dir = 0;

    bool compass = false;
};

#endif // PLAYER_H_INCLUDED
