#pragma once

#include "IParser.h"
class ParserTxt : public IParser {
public:
    ParserTxt();
    std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str);
    void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, std::queue<std::string>& returnParsedData);
};
