#include "implementation.hpp"
#include <algorithm>

Board::Board(const std::vector<std::vector<CellState>> &board) : board(board) {}
Board::Board() : Board(World{}) {}

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

World calculateNextGeneration(const World &world)
{
    World output{};
    Board board{world};

    for (int row = 0; row < board.board.size(); ++row)
    {
        std::vector<CellState> out;
        for (int column = 0; column < board.board[row].size(); ++column)
        {
            int numNeighbors = board.countNeighbors(row, column);

            if (CellState::Alive == board.board[row][column] &&
                numNeighbors == 2)
            {
                out.push_back(CellState::Alive);
            }
            else
            {
                out.push_back(CellState::Dead);
            }
        }
        output.push_back(out);
    }
    return output;
}
