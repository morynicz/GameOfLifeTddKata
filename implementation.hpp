#pragma once
#include <iostream>
#include <vector>

enum class CellState
{
    Dead,
    Alive
};

using Board = std::vector<std::vector<CellState>>;

Board calculateNextGeneration(const Board &);

inline std::ostream &operator<<(std::ostream &str, const CellState in)
{
    switch (in)
    {
    case CellState::Alive:
        str << "Alive";
        break;
    case CellState::Dead:
        str << "Dead";
        break;
    }
    return str;
}

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