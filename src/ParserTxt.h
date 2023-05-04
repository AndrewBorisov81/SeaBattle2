#pragma once
#include "IParser.h"

class ParserTxt : public IParser {
public:
    ParserTxt();
    std::tuple<int, FieldData, std::vector<ShipData>> parseTxt(const std::string& strData) override;
    std::tuple<int, FieldData, std::vector<ShipData>> parseJson(const std::string& pathToJson) override;
    void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, std::queue<std::string>& returnParsedData) override;
};
