#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include <string>
#include <vector>

struct Pattern
{
    virtual std::string operator()(...) = 0;
};

extern Pattern* enterPat; // light?
extern Pattern* appearPat; // light?
extern Pattern* blindPat;
extern Pattern* doorsPat; // vector of directions

#endif // DICTIONARY_H_INCLUDED
