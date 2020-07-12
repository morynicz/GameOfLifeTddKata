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

std::list<Coordinates> Board::getNeighborCoordinates() const
{
    return {Coordinates{-1, -1}, Coordinates{0, -1}, Coordinates{1, -1},
            Coordinates{-1, 0},  Coordinates{1, 0},  Coordinates{-1, 1},
            Coordinates{0, 1},   Coordinates{1, 1}};
}

int Board::countNeighbors(const Coordinates &coords) const
{
    std::list<std::function<bool(const Coordinates &)>> possibleNeighbors{
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{-1, 0}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{1, 0}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{0, -1}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{0, 1}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{-1, -1}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{-1, 1}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{1, -1}),
        std::bind(&Board::hasNeighbor, this, std::placeholders::_1,
                  Coordinates{1, 1})};

    const auto neighborCoordinates = getNeighborCoordinates();

    int numNeighbors =
        std::count_if(neighborCoordinates.begin(), neighborCoordinates.end(),
                      [coords, this](const auto &neighborVector) {
                          return hasNeighbor(coords, neighborVector);
                      });
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
