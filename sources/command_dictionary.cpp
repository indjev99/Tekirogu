#include "../headers/command_dictionary.h"

CommandWord::CommandWord(const std::initializer_list<std::string>& words):
    words(words) {}

std::string tolowerStr(std::string word)
{
    for (char& c : word)
    {
        c = tolower(c);
    }
    return word;
}

bool CommandWord::match(const std::string& word) const
{
    for (const std::string& w : words)
    {
        if (tolowerStr(w) == tolowerStr(word)) return true;
    }
    return false;
}

extern const CommandWord walkCW = {"walk", "go"};
extern const CommandWord turnCW = {"turn", "face"};
extern const CommandWord lookCW = {"look"};

extern const CommandWord aroundDirCW = {"around"};
extern const CommandWord relDirCW[NUM_DIRS] = {
    {"forward", "forwards", "ahead"},
    {"left", "leftward", "leftwards"},
    {"back", "backward", "backwards"},
    {"right", "rightward", "rightwards"}
};
extern const CommandWord absDirCW[NUM_DIRS] = {
    {"North"},
    {"West"},
    {"South"},
    {"East"}
};
