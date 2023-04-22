#include "ParserTxt.h"

#include <string>
#include <queue>
#include <vector>
#include <memory>
#include <algorithm>

#include <gtest/gtest.h>

class ParserTxtTest: public ::testing::Test {
protected:
    void SetUp() override {
         m_parser = std::make_unique<ParserTxt>();
    }

    void TearDown() override {
        m_parser.reset();
    }
    std::unique_ptr<ParserTxt> m_parser;
};

TEST_F(ParserTxtTest, parseAlgorithmSuccess) {
    std::vector<std::string> parseStrings{"5;a", " ", "a;", ";", "6;cf;"};
    std::queue<std::string> expected1;
    expected1.push("5");
    expected1.push("a");
    std::queue<std::string> expected2;
    expected2.push(" ");
    std::queue<std::string> expected3; 
    expected3.push("a");
    std::queue<std::string> expected4;
    expected4.push("");
    std::queue<std::string> expected5;
    expected5.push("6");
    expected5.push("cf");
    std::vector<std::queue<std::string>> expectedParsedStrings{expected1, expected2, expected3, expected4, expected5};

    auto matchContainers = [](const std::queue<std::string>& test, const std::queue<std::string>& expected) {
        EXPECT_EQ(test.size(), expected.size());
        EXPECT_EQ(test, expected);  
    };

    for (int i = 0; i < parseStrings.size(); i++) {
        std::queue<std::string> test;
        std::string parseStr = parseStrings.at(i);
        m_parser->parseAlgorithm(parseStr, std::string(";"), test);
        auto expectedStrq = expectedParsedStrings.at(i);
        matchContainers(test, expectedStrq);
        parseStr.clear();
    }
}
