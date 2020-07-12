#include "gameOfLife/Game.hpp"
#include "gameOfLife/Board.hpp"

World calculateNextGeneration(const World &world)
{
    World output{};
    Board board{world};
    const auto boardLimits = board.getLimits();

    for (int row = 0; row < boardLimits.y; ++row)
    {
        std::vector<CellState> out;
        for (int column = 0; column < boardLimits.x; ++column)
        {
            Coordinates coordinates{column, row};
            int numberOfLivingNeighbors =
                board.countLivingNeighbors(coordinates);

            if (CellState::Alive == board.getCellState(coordinates) and
                numberOfLivingNeighbors == 2)
            {
                out.push_back(CellState::Alive);
            }
            else if (numberOfLivingNeighbors == 3)
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
