#include "Parser.h"

#include <string>
#include <queue>

#include <gtest/gtest.h>


TEST(ParserTest, parseAlgorithm) {
    const std::string parseStr{"5;a"};
    std::queue<std::string> expected;
    expected.push("5");
    expected.push("a");

    Parser parser;
    std::queue<std::string> test;
    parser.parseAlgorithm(parseStr, std::string(";"), test);

    EXPECT_EQ(test.size(), expected.size());
    EXPECT_EQ(test, expected);
}
