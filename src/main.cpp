#include "gameOfLife/Game.hpp"

int main()
{
    World input(6, World::value_type(6, CellState::Dead));
    input[2][1] = CellState::Alive;
    input[2][2] = CellState::Alive;
    input[2][3] = CellState::Alive;

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "gen: " << i << " -------------------------------"
                  << std::endl;
        for (const auto &row : input)
        {
            for (const auto &cell : row)
            {
                switch (cell)
                {
                case CellState::Alive:
                    std::cout << "O";
                    break;

                default:
                    std::cout << ".";
                    break;
                }
            }
            std::cout << std::endl;
        }
        input = calculateNextGeneration(input);
    }
}