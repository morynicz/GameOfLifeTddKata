#include "gtest/gtest.h"
#include "implementation.hpp"

TEST(Board1x1Tests, cellStaysDead)
{
    Board input{false};
    Board output{false};
    EXPECT_EQ(output, calculateNextGeneration(input));
}

TEST(Board3x3Tests, aliveCellBecomesDead)
{
    Board input{false, false, false, false, true, false, false, false, false};
    Board output{false,false,false, false, false, false, false, false, false};
    EXPECT_EQ(output, calculateNextGeneration(input));
}