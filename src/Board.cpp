#include "gameOfLife/Board.hpp"

Board::Board(const std::vector<std::vector<CellState>> &board) : board(board) {}

bool Board::hasNeighborOnTheLeft(const Coordinates &coords) const
{
    return (coords.x - 1) >= 0 &&
           CellState::Alive == board[coords.y][coords.x - 1];
}

bool Board::hasNeighborOnTheRight(const Coordinates &coords) const
{
    return (coords.x + 1) < board[coords.y].size() &&
           CellState::Alive == board[coords.y][coords.x + 1];
}

bool Board::hasNeighborAbove(const Coordinates &coords) const
{
    return 0 <= (coords.y - 1) and
           CellState::Alive == board[coords.y - 1][coords.x];
}

bool Board::hasNeighborBelow(const Coordinates &coords) const
{
    return board.size() > (coords.y + 1) and
           CellState::Alive == board[coords.y + 1][coords.x];
}

int Board::countNeighbors(const Coordinates &coords) const
{
    int numNeighbors{0};
    if (hasNeighborOnTheLeft(coords))
    {
        ++numNeighbors;
    }
    if (hasNeighborOnTheRight(coords))
    {
        ++numNeighbors;
    }
    if (hasNeighborAbove(coords))
    {
        ++numNeighbors;
    }
    if (hasNeighborBelow(coords))
    {
        ++numNeighbors;
    }
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
