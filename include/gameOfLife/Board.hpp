#pragma once
#include "gameOfLife/Coordinates.hpp"
#include "gameOfLife/Game.hpp"

class Board
{
  public:
    Board(const World &);
    int countNeighbors(const Coordinates &coords) const;
    CellState getCellState(const Coordinates &coords) const;
    Coordinates getLimits() const;
    bool operator==(const Board &rhs) const;

  private:
    bool hasNeighborOnTheLeft(const Coordinates &coords) const;
    bool hasNeighborOnTheRight(const Coordinates &coords) const;
    bool hasNeighborAbove(const Coordinates &coords) const;
    bool hasNeighborBelow(const Coordinates &coords) const;
    bool hasNeighborOnUpperLeft(const Coordinates &coords) const;
    bool hasNeighborOnUpperRight(const Coordinates &coords) const;
    bool hasNeighborOnLowerLeft(const Coordinates &coords) const;
    bool hasNeighborOnLowerRight(const Coordinates &coords) const;

    bool isOnLeftEdge(const Coordinates &coords) const;
    bool isOnRightEdge(const Coordinates &coords) const;
    bool isOnUpperEdge(const Coordinates &coords) const;
    bool isOnLowerEdge(const Coordinates &coords) const;

    World board;
};