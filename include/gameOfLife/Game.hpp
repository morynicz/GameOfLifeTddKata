#pragma once
#include "gameOfLife/World.hpp"
#include <iostream>

World calculateNextGeneration(const World &);

template <typename T>
inline std::ostream &operator<<(std::ostream &str, const std::vector<T> &in)
{
    str << "{ ";
    for (const auto &it : in)
    {
        str << it << " ";
    }
    return str << "}";
}