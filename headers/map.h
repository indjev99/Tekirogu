#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "room.h"

#include <map>
#include <utility>

struct Map
{
private:
    static const int MAX_GEN_ITERS = 1000;
    static const int CHUNK_LOG_SIZE = 4;
    static const int CHUNK_SIZE = 1 << CHUNK_LOG_SIZE;
    struct Chunk
    {
        Room rooms[CHUNK_SIZE][CHUNK_SIZE];
    };
    std::map<std::pair<int, int>, Chunk> chunks;

    static bool chunkMove(int& x, int& cx);
    Room& findRoom(int& x, int& y, int& cx, int& cy, Chunk*& chunk);
    Room& findNextRoom(int& x, int& y, int& cx, int& cy, Chunk*& chunk);
    void addToMap(int& x, int& y, int& cx, int& cy, Chunk*& chunk);

public:
    Map();
    const Room& room(int x, int y);
    const Room& distantRoom(int fromX, int fromY, int toX, int toY);
};

#endif // MAP_H_INCLUDED
