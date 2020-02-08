#include "../headers/randomizer.h"

#include <random>

static std::default_random_engine generator;

void seedRand(int seed)
{
    generator.seed(seed);
}

int randInt(int upb)
{
    std::uniform_int_distribution<int> distribution(0, upb - 1);
    return distribution(generator);
}
