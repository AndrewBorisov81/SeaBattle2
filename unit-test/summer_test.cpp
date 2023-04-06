#include "summer.h"

#include <gtest/gtest.h>

TEST(SummerTest, SumTest) {
    // Test case 1: positive numbers
    EXPECT_EQ(sum(2, 3), 5);
    EXPECT_EQ(sum(10, 20), 30);
    
    // Test case 2: negative numbers
    EXPECT_EQ(sum(-5, -10), -15);
    
    // Test case 3: mixed positive and negative numbers
    EXPECT_EQ(sum(-5, 10), 5);
    EXPECT_EQ(sum(20, -10), 10);
}
