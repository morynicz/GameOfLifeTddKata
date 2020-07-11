#include "gtest/gtest.h"
#include "implementation.hpp"

TEST(1x1BoardTests, cellStaysDead)
{
    Board input{false};
    Board output{false};
    EXPECT_EQ(output, calculateNextGeneration(input));
}