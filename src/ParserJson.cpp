#include "ParserJson.h"

ParserJson::ParserJson() {

}

std::tuple<int, FieldData, std::vector<ShipData>> ParserJson::parse(const std::string& str) {
    std::string s = std::move(str);
    

    FieldData fieldData;
    int n = 0;
    std::vector<ShipData> ships; 
    return std::tuple<int, FieldData, std::vector<ShipData>>{n, fieldData, ships};
}

void ParserJson::parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, std::queue<std::string>& returnParsedData) {
}
