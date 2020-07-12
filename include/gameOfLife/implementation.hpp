#pragma once
#include "gameOfLife/CellState.hpp"
#include <iostream>
#include <vector>

using World = std::vector<std::vector<CellState>>;

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