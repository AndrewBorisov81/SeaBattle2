#pragma once
#include <string>
#include <queue>
#include <tuple>
#include "UtilityData.h"

class IParser {
public:
    virtual ~IParser(){};
    virtual std::tuple<int, FieldData, std::vector<ShipData>> parseTxt(const std::string& strData) = 0;
    virtual std::tuple<int, FieldData, std::vector<ShipData>> parseJson(const std::string& pathToJson) = 0;
    virtual void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, 
                               std::queue<std::string>& returnParsedData) = 0;
};
