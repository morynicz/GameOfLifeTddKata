#pragma once

#include <ostream>

enum class CellState
{
    Dead,
    Alive
};

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