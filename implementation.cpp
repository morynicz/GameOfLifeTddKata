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

Board calculateNextGeneration(const Board &in)
{
    Board output;

    std::transform(in.begin(), in.end(), std::back_inserter(output),
                   [](const auto &input) {
                       std::vector<CellState> out;

                       for (int i = 0; i < input.size(); ++i)
                       {
                           int numNeighbors{0};
                           if (hasNeighborOnTheLeft(input, i))
                           {
                               ++numNeighbors;
                           }
                           if (hasNeighborOnTheRight(input, i))
                           {
                               ++numNeighbors;
                           }
                           if (CellState::Alive == input[i] &&
                               numNeighbors == 2)
                           {
                               out.push_back(CellState::Alive);
                           }
                           else
                           {
                               out.push_back(CellState::Dead);
                           }
                       }
                       return out;
                   });
    return output;
}
