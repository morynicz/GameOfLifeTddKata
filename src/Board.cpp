#include "gameOfLife/Board.hpp"

Board::Board(const std::vector<std::vector<CellState>> &board) : board(board) {}

bool Board::hasNeighborOnTheLeft(const int row, const int column) const
{
    return (column - 1) >= 0 && CellState::Alive == board[row][column - 1];
}

bool Board::hasNeighborOnTheRight(const int row, const int column) const
{
    return (column + 1) < board[row].size() &&
           CellState::Alive == board[row][column + 1];
}

bool Board::hasNeighborAbove(const int row, const int column) const
{
    return 0 <= (row - 1) and CellState::Alive == board[row - 1][column];
}

bool Board::hasNeighborBelow(const int row, const int column) const
{
    return board.size() > (row + 1) and
           CellState::Alive == board[row + 1][column];
}

int Board::countNeighbors(const int row, const int column) const
{
    int numNeighbors{0};
    if (hasNeighborOnTheLeft(row, column))
    {
        ++numNeighbors;
    }
    if (hasNeighborOnTheRight(row, column))
    {
        ++numNeighbors;
    }
    if (hasNeighborAbove(row, column))
    {
        ++numNeighbors;
    }
    if (hasNeighborBelow(row, column))
    {
        ++numNeighbors;
    }
    return numNeighbors;
}

CellState Board::getCellState(const int row, const int column) const
{
    return board[row][column];
}

Coordinates Board::getLimits() const
{
    auto limX = board.empty() ? 0l : board.front().size();
    return Coordinates{limX, board.size()};
}

bool Board::operator==(const Board &rhs) const { return board == rhs.board; }
