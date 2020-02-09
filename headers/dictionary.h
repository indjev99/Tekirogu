#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include <string>
#include <vector>

struct Pattern
{
    virtual std::string operator()(...) const = 0;
};

extern const Pattern* const unknownCmdPat;
extern const Pattern* const enterPat; // light
extern const Pattern* const appearPat; // light
extern const Pattern* const blindPat;
extern const Pattern* const doorsPat; // vector of directions
extern const Pattern* const turnPat; // direction
extern const Pattern* const unknownAbsPat; // direction
extern const Pattern* const noDoorPat; // direction

#endif // DICTIONARY_H_INCLUDED
