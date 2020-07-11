#include "gtest/gtest.h"
#include "implementation.hpp"

TEST(test, tee)
{
    std::list<bool> input{false};
    std::list<bool> output{false};
    EXPECT_EQ(output, fun(input));
}