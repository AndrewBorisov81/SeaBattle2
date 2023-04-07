#include "Parser.h"

#include <string>
#include <queue>
#include <memory>

#include <gtest/gtest.h>

class ParserTest: public ::testing::Test {
protected:
    void SetUp() override {
         m_parser = std::make_unique<Parser>();
    }

    void TearDown() override {
        m_parser.reset();
    }
    std::unique_ptr<Parser> m_parser;
};

TEST_F(ParserTest, parseAlgorithmSuccess) {
    const std::string parseStr{"5;a"};
    std::queue<std::string> expected;
    expected.push("5");
    expected.push("a");

    std::queue<std::string> test;
    m_parser->parseAlgorithm(parseStr, std::string(";"), test);

    auto matchContainers = [](const std::queue<std::string>& test, const std::queue<std::string>& expected) {
        EXPECT_EQ(test.size(), expected.size());
        EXPECT_EQ(test, expected);  
    };

    matchContainers(test, expected);

    /*EXPECT_EQ(test.size(), expected.size());
    EXPECT_EQ(test, expected);*/
}
