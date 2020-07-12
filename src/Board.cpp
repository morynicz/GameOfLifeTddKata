#include "gameOfLife/Board.hpp"
#include <algorithm>
#include <functional>
#include <list>

Board::Board(const std::vector<std::vector<CellState>> &board) : board(board) {}

bool Board::hasNeighbor(const Coordinates &coords, const Coordinates &mod) const
{
    try
    {
        return CellState::Alive ==
               board.at(coords.y + mod.y).at(coords.x + mod.x);
    }
    catch (std::out_of_range)
    {
        return false;
    }
}

bool Board::hasNeighborOnTheLeft(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{-1, 0});
}

bool Board::hasNeighborOnTheRight(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{1, 0});
}

bool Board::hasNeighborAbove(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{0, -1});
}

bool Board::hasNeighborBelow(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{0, 1});
}

bool Board::hasNeighborOnUpperLeft(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{-1, -1});
}

bool Board::hasNeighborOnUpperRight(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{1, -1});
}

bool Board::hasNeighborOnLowerLeft(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{-1, 1});
}

bool Board::hasNeighborOnLowerRight(const Coordinates &coords) const
{
    return hasNeighbor(coords, Coordinates{1, 1});
}

int Board::countNeighbors(const Coordinates &coords) const
{
    std::list<std::function<bool(const Coordinates &)>> possibleNeighbors{
        std::bind(&Board::hasNeighborOnTheLeft, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborOnTheRight, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborAbove, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborBelow, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborOnUpperLeft, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborOnUpperRight, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborOnLowerLeft, this, std::placeholders::_1),
        std::bind(&Board::hasNeighborOnLowerRight, this,
                  std::placeholders::_1)};

    int numNeighbors =
        std::count_if(possibleNeighbors.begin(), possibleNeighbors.end(),
                      [coords](const auto &test) { return test(coords); });
    return numNeighbors;
}

CellState Board::getCellState(const Coordinates &coords) const
{
    return board[coords.y][coords.x];
}

Coordinates Board::getLimits() const
{
    auto limX = board.empty() ? 0l : board.front().size();
    return Coordinates{limX, board.size()};
}

bool Board::operator==(const Board &rhs) const { return board == rhs.board; }
