#include "Parser.h"

#include <gtest/gtest.h>

#include <string>
#include <queue>

TEST(ParserTest, parseAlgorithm) {
    // Test case 1: positive numbers
    const std::string s1{5;a};
    const std::queue<std::string> expected{"5", "a"};

    std::queue<std::string> test;
    parseAlgorithm(s1, std::string(";"), test);

    EXPECT_EQ(test, expected);
    //EXPECT_EQ(sum(10, 20), 30);
    
    // Test case 2: negative numbers
    //EXPECT_EQ(sum(-5, -10), -15);
    
    // Test case 3: mixed positive and negative numbers
    //EXPECT_EQ(sum(-5, 10), 5);
    //EXPECT_EQ(sum(20, -10), 10);
}
