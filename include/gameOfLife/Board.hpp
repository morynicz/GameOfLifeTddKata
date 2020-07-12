#pragma once
#include "gameOfLife/Coordinates.hpp"
#include "gameOfLife/Game.hpp"
#include <list>

class Board
{
  public:
    Board(const World &);
    int countLivingNeighbors(const Coordinates &coords) const;
    CellState getCellState(const Coordinates &coords) const;
    Coordinates getLimits() const;
    bool operator==(const Board &rhs) const;

  private:
    bool hasNeighbor(const Coordinates &coords, const Coordinates &mod) const;
    std::list<Coordinates> getNeighborCoordinates() const;
    World board;
};