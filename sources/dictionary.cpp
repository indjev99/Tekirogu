#ifndef DICTIONARY_CPP_INCLUDED
#define DICTIONARY_CPP_INCLUDED

#include "../headers/dictionary.h"
#include "../headers/directions.h"
#include "../headers/randomizer.h"
#include <vector>
#include <algorithm>
#include <stdarg.h>

struct OnePattern
{
private:
    std::vector<std::string> parts;
public:
    OnePattern(const std::initializer_list<std::string>& parts):
        parts(parts) {}
    std::string operator()(const std::vector<std::string>& words) const
    {
        std::string result = parts[0];
        for (size_t i = 1; i < parts.size(); ++i)
        {
            result += words[i - 1];
            result += parts[i];
        }
        return result;
    }
};

const std::vector<OnePattern> noDoors =  {
    {"There aren't any doors."},
    {"There don't seem to be any doors."},
    {"You don't see any doors."},
    {"You can't see any doors."},
    {"It appears there are no doors."}
};
const std::vector<OnePattern> oneDoor =  {
    {"There is a door ", "."},
    {"There is one door ", "."},
    {"You see a door ", "."},
    {"You see one door ", "."}
};
const std::vector<OnePattern> twoDoors =  {
    {"There are doors ", " and ", "."},
    {"There is one door ", " and one ", "."},
    {"There is a door ", " as well as one ", "."},
    {"There is one door ", " as well as one ", "."},
    {"There are two doors: ", " and ", "."},
    {"You see doors ", " and ", "."},
    {"You see one door ", " and one ", "."},
    {"You see a door ", " as well as one ", "."},
    {"You see one door ", " as well as one ", "."},
    {"You see two doors: ", " and ", "."}
};
const std::vector<OnePattern> threeDoors =  {
    {"There are doors ", ", ", " and ", "."},
    {"There is one door ", ", one ", " and one ", "."},
    {"There are doors ", " and ", " as well as one ", "."},
    {"There are three doors: ", ", ", " and ", "."},
    {"You see doors ", ", ", " and ", "."},
    {"You see one door ", ", one ", " and one ", "."},
    {"You see doors ", " and ", " as well as one ", "."},
    {"You see three doors: ", ", ", " and ", "."}
};
const std::vector<OnePattern> fourDoors =  {
    {"There are doors ", ", ", ", ", " and ", "."},
    {"There is one door ", ", one ", ", one ", " and one ", "."},
    {"There are doors ", " and ", " as well as ", " and ", "."},
    {"There are four doors: ", ", ", ", ", " and ", "."},
    {"You see doors ", ", ", ", ", " and ", "."},
    {"You see one door ", ", one ", ", one ", " and one ", "."},
    {"You see doors ", " and ", " as well as ", " and ", "."},
    {"You see four doors: ", ", ", ", ", " and ", "."}
};
const std::vector<OnePattern> doors[] = {
    noDoors, oneDoor, twoDoors, threeDoors, fourDoors
};
const std::vector<std::vector<std::string>> dirNames = {
    {"in front of you", "to the left", "behind you", "to the right"},
    {"in front of you", "to your left", "behind you", "to your right"},
    {"in front of you", "on the left wall", "behind you", "on the right wall"},
    {"on the wall facing you", "on the left wall", "on the wall behind you", "on the right wall"},
};
const std::vector<OnePattern> lightEnter =  {
    {"You enter a room."},
    {"You walk into a room."},
    {"You step into a room."},
    {"You step inside a room."}
};
const std::vector<OnePattern> darkEnter =  {
    {"You enter a dark room."},
    {"You walk into a dark room."},
    {"You step into a dark room."},
    {"You step inside a dark room."}
};
const std::vector<OnePattern> enters[] = {
    darkEnter, lightEnter
};
const std::vector<OnePattern> lightAppear =  {
    {"You are in a room."}
};
const std::vector<OnePattern> darkAppear =  {
    {"You are in a dark room."}
};
const std::vector<OnePattern> appears[] = {
    darkAppear, lightAppear
};
const std::vector<OnePattern> blinds =  {
    {"You can't see anything."},
    {"You can't see anything in the darkness."},
    {"You can't see anything around you."},
};

struct EnterPat : Pattern
{
    std::string operator()(...) override
    {
        va_list arguments;
        va_start(arguments, 0);
        int light = va_arg(arguments, int);
        va_end(arguments);
        const std::vector<OnePattern>& ps = enters[light];
        return ps[randInt(ps.size())]({});
    }
};
struct AppearPat : Pattern
{
    std::string operator()(...) override
    {
        va_list arguments;
        va_start(arguments, 0);
        int light = va_arg(arguments, int);
        va_end(arguments);
        const std::vector<OnePattern>& ps = appears[light];
        return ps[randInt(ps.size())]({});
    }
};
struct BlindPat : Pattern
{
    std::string operator()(...) override
    {
        return blinds[randInt(blinds.size())]({});
    }
};
int dirPriorities[] = {2, 0, 3, 1};
bool dirCmp(int dir1, int dir2)
{
    return dirPriorities[dir1] < dirPriorities[dir2];
}
struct DoorsPat : Pattern
{
    std::string operator()(...) override
    {
        va_list arguments;
        va_start(arguments, 0);
        std::vector<int> doorDirs = va_arg(arguments, std::vector<int>);
        va_end(arguments);
        std::sort(doorDirs.begin(), doorDirs.end(), dirCmp);
        std::vector<std::string> words;
        int setNum = randInt(dirNames.size());
        for (int d : doorDirs)
        {
            words.push_back(dirNames[setNum][d]);
        }
        const std::vector<OnePattern>& ps = doors[doorDirs.size()];
        return ps[randInt(ps.size())](words);
    }
};

Pattern* enterPat = new EnterPat();
Pattern* appearPat = new AppearPat();
Pattern* blindPat = new BlindPat();
Pattern* doorsPat = new DoorsPat();

#endif // DICTIONARY_CPP_INCLUDED
