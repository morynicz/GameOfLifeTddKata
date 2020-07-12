#pragma once
#include "gameOfLife/Coordinates.hpp"
#include "gameOfLife/Game.hpp"

class Board
{
  public:
    Board(const World &);
    int countNeighbors(const int row, const int column) const;
    CellState getCellState(const int row, const int column) const;
    Coordinates getLimits() const;
    bool operator==(const Board &rhs) const;

  private:
    bool hasNeighborOnTheLeft(const int row, const int column) const;
    bool hasNeighborOnTheRight(const int row, const int column) const;
    bool hasNeighborAbove(const int row, const int column) const;
    bool hasNeighborBelow(const int row, const int column) const;

    World board;
};