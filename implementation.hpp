#pragma once
#include <iostream>
#include <vector>

enum class CellState
{
    Dead,
    Alive
};

using World = std::vector<std::vector<CellState>>;

class Board
{
  public:
    Board(const std::vector<std::vector<CellState>> &);
    Board();
    int countNeighbors(const int row, const int column) const;
    inline bool operator==(const Board &rhs) const
    {
        return board == rhs.board;
    }
    std::vector<std::vector<CellState>> board;

  private:
    bool hasNeighborOnTheLeft(const int row, const int column) const;
    bool hasNeighborOnTheRight(const int row, const int column) const;
    bool hasNeighborAbove(const int row, const int column) const;
    bool hasNeighborBelow(const int row, const int column) const;
};

World calculateNextGeneration(const World &);

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