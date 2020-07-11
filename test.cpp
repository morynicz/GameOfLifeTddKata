#include "implementation.hpp"
#include "gtest/gtest.h"

TEST(Board1x1Tests, cellStaysDead)
{
    Board input{{CellState::Dead}};
    Board output{{CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(Board3x3Tests, aliveCellBecomesDead)
{
    Board input{{CellState::Dead, CellState::Dead, CellState::Dead},
                {CellState::Dead, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Dead}};
    Board output{{CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(Board3x3Tests, aliveCellWithTwoNeighborsInRowStaysAlive)
{
    Board input{{CellState::Dead, CellState::Dead, CellState::Dead},
                {CellState::Alive, CellState::Alive, CellState::Alive},
                {CellState::Dead, CellState::Dead, CellState::Dead}};
    Board output{{CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Alive, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}
