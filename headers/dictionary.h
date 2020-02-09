#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include <string>
#include <vector>

struct Pattern
{
    virtual std::string operator()(...) = 0;
};

extern Pattern* enterPat;
extern Pattern* blindPat;
extern Pattern* doorsPat;

#endif // DICTIONARY_H_INCLUDED
