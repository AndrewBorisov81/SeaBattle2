#pragma once
#include <string>
#include <queue>
#include <tuple>
#include "UtilityData.h"

class IParser {
public:
    virtual ~IParser(){};
    virtual std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str) = 0;
    virtual void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, 
                               std::queue<std::string>& returnParsedData) = 0;
};
