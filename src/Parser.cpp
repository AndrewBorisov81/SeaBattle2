#include "Parser.h"
#include <queue>
#include <vector>

Parser::Parser() {

}

std::tuple<int, FieldData, std::vector<ShipData>> Parser::parse(const std::string& str) {
    std::queue<std::string> tokens;
    std::string levelData = str;
    std::string delimeter = ";";
    parseAlgorithm(levelData, delimeter, tokens);
    int level{};
    if (!tokens.empty()) {
        level = std::stoi(tokens.front());
        tokens.pop();
    }

    enum class FieldAttr{rows = 0, columns, width, height};
    FieldData fieldData = {};
    if(!tokens.empty()) {
        std::vector<int> parsedFieldData;
        std::queue<std::string> qparsedFieldData;
        std::string parseFieldData = tokens.front();
        tokens.pop();
        delimeter = ",";
        parseAlgorithm(parseFieldData, delimeter, qparsedFieldData);
        while(!qparsedFieldData.empty()) {
            std::string str = qparsedFieldData.front();
            parsedFieldData.push_back(std::stoi(str));
            qparsedFieldData.pop();
        }
        if(parsedFieldData.size() >= 4) {
            /*fieldData = {parsedFieldData.at(static_cast<int>(FieldAttr::rows)), 
            parsedFieldData.at(static_cast<int>(FieldAttr::columns)),
            parsedFieldData.at(static_cast<int>(FieldAttr::width)),
            parsedFieldData.at(static_cast<int>(FieldAttr::height))};*/
            fieldData.columns = parsedFieldData.at(static_cast<int>(FieldAttr::rows));
            fieldData.rows = parsedFieldData.at(static_cast<int>(FieldAttr::columns));
        }
    }

    std::vector<ShipData> shipsData;
    enum class ShipAttr{type = 0, initRow, initColumn, direction};
    while(!tokens.empty()){
        std::string parseShipData = tokens.front();
        tokens.pop();
        delimeter = ",";
        std::vector<int> parsedShipData;
        std::queue<std::string> qparsedShipData;
        parseAlgorithm(parseShipData, delimeter, qparsedShipData);
        while(!qparsedShipData.empty()) {
            std::string str = qparsedShipData.front();
            parsedShipData.push_back(std::stoi(str));
            qparsedShipData.pop();
        }
        if(parsedShipData.size() >= 4) {
            ShipData shipData{parsedShipData.at(static_cast<int>(ShipAttr::type)), 
            parsedShipData.at(static_cast<int>(ShipAttr::initRow)), 
            parsedShipData.at(static_cast<int>(ShipAttr::initColumn)), 
            parsedShipData.at(static_cast<int>(ShipAttr::direction))};
            shipsData.push_back(shipData);
        }
    }
    return std::tuple<int, FieldData, std::vector<ShipData>>{level, fieldData, shipsData};
}

void Parser::parseAlgorithm(const std::string& stringToParse, 
                            const std::string& delimeter, std::queue<std::string>& returnParsedData) {
    std::queue<std::string> tokens;
    std::string stringData = stringToParse;

    size_t pos = 0;
    std::string token;
    while ((pos = stringData.find(delimeter)) != std::string::npos) {
        token = stringData.substr(0, pos);
        tokens.push(token);
        stringData.erase(0, pos + delimeter.length());
    }
    if (!stringData.empty()) {
        token = stringData.substr(0, stringData.length());
        tokens.push(token);
    }

    returnParsedData = tokens;
}
