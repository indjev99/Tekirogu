#include "../headers/map.h"
#include "../headers/randomizer.h"

Map::Map()
{
    chunks[{0, 0}].rooms[0][0].generated = true;
}

bool Map::chunkMove(int& x, int& cx)
{
    if (x >= CHUNK_SIZE)
    {
        x -= CHUNK_SIZE;
        ++cx;
        return true;
    }
    if (x < 0)
    {
        x += CHUNK_SIZE;
        --cx;
        return true;
    }
    return false;
}

Room& Map::findRoom(int& x, int& y, int& cx, int& cy, Chunk*& chunk)
{
    cx = x >> CHUNK_LOG_SIZE;
    cy = y >> CHUNK_LOG_SIZE;
    x -= cx << CHUNK_LOG_SIZE;
    y -= cy << CHUNK_LOG_SIZE;
    chunk = &chunks[{cx, cy}];
    return chunk->rooms[x][y];
}

Room& Map::findNextRoom(int& x, int& y, int& cx, int& cy, Chunk*& chunk)
{
    if (chunkMove(x, cx) || chunkMove(y, cy))
    {
        chunk = &chunks[{cx, cy}];
    }
    return chunk->rooms[x][y];
}

void Map::addToMap(int& x, int& y, int& cx, int& cy, Chunk*& chunk)
{
    Room& room = findNextRoom(x, y, cx, cy, chunk);
    int x0 = x, y0 = y, cx0 = cx, cy0 = cy;
    Chunk* chunk0 = chunk;
    if (!room.generated)
    {
        Room* curr = nullptr;
        do
        {
            x = x0;
            y = y0;
            cx = cx0;
            cy = cy0;
            chunk = chunk0;
            curr = &room;
            int cnt = 0;
            while (!curr->generated && cnt++ < MAX_GEN_ITERS)
            {
                int dir = randInt(NUM_DIRS);
                curr->dirToSource = dir;
                moveInDir(dir, x, y);
                curr = &findNextRoom(x, y, cx, cy, chunk);
            }
        }
        while (!curr->generated);

        x = x0;
        y = y0;
        cx = cx0;
        cy = cy0;
        chunk = chunk0;
        curr = &room;
        while (!curr->generated)
        {
            int dir = curr->dirToSource;
            curr->doors[dir] = 1;
            curr->generated = true;
            moveInDir(dir, x, y);
            curr = &findNextRoom(x, y, cx, cy, chunk);
            curr->doors[turnBack(dir)] = 1;
        }
    }

    x = x0;
    y = y0;
    cx = cx0;
    cy = cy0;
    chunk = chunk0;
}

const Room& Map::room(int x, int y)
{
    int cx, cy;
    Chunk* chunk;
    Room& room = findRoom(x, y, cx, cy, chunk);
    addToMap(x, y, cx, cy, chunk);
    for (int d = 0; d < NUM_DIRS; ++d)
    {
        int x2 = x, y2 = y, cx2 = cx, cy2 = cy;
        Chunk* chunk2 = chunk;
        moveInDir(d, x2, y2);
        addToMap(x2, y2, cx2, cy2, chunk2);
    }
    return room;
}

static void moveBoth(int& x, int& fromX, int& toX)
{
    if (fromX < toX)
    {
        ++fromX;
        ++x;
    }
    if (fromX > toX)
    {
        --fromX;
        --x;
    }
}

const Room& Map::distantRoom(int fromX, int fromY, int toX, int toY)
{
    int x = fromX, y = fromY, cx, cy;
    Chunk* chunk;
    findRoom(x, y, cx, cy, chunk);
    bool turnX = true;
    while (fromX != toX && fromY != toY)
    {
        if ((turnX && fromX != toX) || fromY == toY) moveBoth(x, fromX, toX);
        else moveBoth(y, fromY, toY);
        turnX = !turnX;
        addToMap(x, y, cx, cy, chunk);
    }
    return room(toX, toY);
}
