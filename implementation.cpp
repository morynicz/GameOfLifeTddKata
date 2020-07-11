#include "implementation.hpp"
#include <algorithm>

bool hasNeighborOnTheLeft(const std::vector<CellState> &row, const int idx)
{
    return (idx - 1) >= 0 && CellState::Alive == row[idx - 1];
}

bool hasNeighborOnTheRight(const std::vector<CellState> &row, const int idx)
{
    return (idx + 1) < row.size() && CellState::Alive == row[idx + 1];
}

bool hasNeighborAbove(const Board &board, const int row, const int column)
{
    return 0 <= (row - 1) and CellState::Alive == board[row - 1][column];
}

bool hasNeighborBelow(const Board &board, const int row, const int column)
{
    return board.size() > (row + 1) and
           CellState::Alive == board[row + 1][column];
}

Board calculateNextGeneration(const Board &board)
{
    Board output;

    for (int row = 0; row < board.size(); ++row)
    {
        std::vector<CellState> out;
        for (int column = 0; column < board[row].size(); ++column)
        {
            int numNeighbors{0};
            if (hasNeighborOnTheLeft(board[row], column))
            {
                ++numNeighbors;
            }
            if (hasNeighborOnTheRight(board[row], column))
            {
                ++numNeighbors;
            }
            if (hasNeighborAbove(board, row, column))
            {
                ++numNeighbors;
            }
            if (hasNeighborBelow(board, row, column))
            {
                ++numNeighbors;
            }

            if (CellState::Alive == board[row][column] && numNeighbors == 2)
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
