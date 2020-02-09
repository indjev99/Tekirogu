#ifndef COMMAND_DICTIONARY_H_INCLUDED
#define COMMAND_DICTIONARY_H_INCLUDED

#include "directions.h"
#include <string>
#include <vector>

struct CommandWord
{
private:
    std::vector<std::string> words;
public:
    CommandWord(const std::initializer_list<std::string>& words);
    bool match(const std::string& word) const;
};

extern const CommandWord walkCW;
extern const CommandWord turnCW;
extern const CommandWord lookCW;

extern const CommandWord aroundDirCW;
extern const CommandWord relDirCW[NUM_DIRS];
extern const CommandWord absDirCW[NUM_DIRS];

#endif // COMMAND_DICTIONARY_H_INCLUDED
