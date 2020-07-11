#include "implementation.hpp"
#include <algorithm>

Board calculateNextGeneration(const Board& in)
{
    Board output;
    std::transform(in.begin(), in.end(), std::back_inserter(output), [](const auto&){return false;});
    return output;
}
