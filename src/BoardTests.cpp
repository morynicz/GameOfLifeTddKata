#include "gameOfLife/Board.hpp"
#include "gtest/gtest.h"

TEST(Board3x3Tests, cellInCenterWithNoNeighborsHas0Neigbors)
{
    World input{{CellState::Dead, CellState::Dead, CellState::Dead},
                {CellState::Dead, CellState::Alive, CellState::Dead},
                {CellState::Dead, CellState::Dead, CellState::Dead}};
    Board board{input};
    EXPECT_EQ(0, board.countNeighbors(Coordinates{1, 1}));
}

struct Board3x3OneNeighborTests : public testing::TestWithParam<World>
{
};

TEST_P(Board3x3OneNeighborTests, cellInCenterWithNoNeighborsHas0Neigbors)
{
    Board board{GetParam()};
    EXPECT_EQ(1, board.countNeighbors(Coordinates{1, 1}));
}

INSTANTIATE_TEST_SUITE_P(
    OneNeighborTests, Board3x3OneNeighborTests,
    testing::Values(World{{CellState::Dead, CellState::Dead, CellState::Dead},
                          {CellState::Alive, CellState::Alive, CellState::Dead},
                          {CellState::Dead, CellState::Dead, CellState::Dead}},
                    World{{CellState::Dead, CellState::Dead, CellState::Dead},
                          {CellState::Dead, CellState::Alive, CellState::Alive},
                          {CellState::Dead, CellState::Dead, CellState::Dead}},
                    World{{CellState::Dead, CellState::Alive, CellState::Dead},
                          {CellState::Dead, CellState::Alive, CellState::Dead},
                          {CellState::Dead, CellState::Dead, CellState::Dead}},
                    World{{CellState::Dead, CellState::Dead, CellState::Dead},
                          {CellState::Dead, CellState::Alive, CellState::Dead},
                          {CellState::Dead, CellState::Alive, CellState::Dead}}

                    ));