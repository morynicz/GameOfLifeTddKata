#include "gameOfLife/Game.hpp"
#include "gtest/gtest.h"

TEST(World1x1Tests, cellStaysDead)
{
    World input{{CellState::Dead}};
    World output{{CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(World3x3Tests, aliveCellBecomesDead)
{
    World input{{CellState::Dead, CellState::Dead, CellState::Dead},
                {CellState::Dead, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Dead}};
    World output{{CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(World3x3Tests,
     aliveCellWithTwoNeighborsOneOnLowerRightAndAnotherInUpperLeftStaysAlive)
{
    World input{{CellState::Alive, CellState::Dead, CellState::Dead},
                {CellState::Dead, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Alive}};
    World output{{CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Alive, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(World3x3Tests,
     aliveCellWithTwoNeighborsOneLowerLeftAndOneInUpperRightStaysAlive)
{
    World input{{CellState::Dead, CellState::Dead, CellState::Alive},
                {CellState::Dead, CellState::Alive, CellState::Dead},
                {CellState::Alive, CellState::Dead, CellState::Dead}};
    World output{{CellState::Dead, CellState::Dead, CellState::Dead},
                 {CellState::Dead, CellState::Alive, CellState::Dead},
                 {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(World3x3Tests, aliveCellWithThreeNeighborsStaysAlive)
{
    World input{{CellState::Alive, CellState::Alive, CellState::Dead},
                {CellState::Alive, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Dead}};;
    World output{{CellState::Alive, CellState::Alive, CellState::Dead},
                {CellState::Alive, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Dead}};
    EXPECT_EQ(output, calculateNextGeneration(input));
}