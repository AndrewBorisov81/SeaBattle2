/*json jgamelevel = {
    {"level" , 1},
    {"field", {{"rows", 12}, {"columns", 12}, {"rowWidth", 25}, {"rowHight", 25}}},
    {"fourDecksShip", {{"decks, 4"}, {"beginRowCell", 1}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"threeDecksShip", {{"decks, 3"}, {"beginRowCell", 3}, {"beginColumnCell, 3"}, {"isHorizontal, true"}}},
    {"twoDecksShip", {{"decks, 2"}, {"beginRowCell", 7}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"oneDecksShip", {{"decks, 1"}, {"beginRowCell", 12}, {"beginColumnCell, 12"}, {"isHorizontal, false"}}},
};*/

//std::ifstream f("/Users/andrewborisov/Desktop/Dev/Projects/Cpp/VSCode/SeaBattle/levelData.json");

#include "ParserJson.h"

#include <fstream>
#include <algorithm>

#include <json/json.h>

ParserJson::ParserJson() {

}

std::tuple<int, FieldData, std::vector<ShipData>> ParserJson::parseJson(const std::string& pathToJson) {
    FieldData fieldData{};
    int level{0};
    std::vector<std::string> typeDecksShip = {"fourDecksShip", "threeDecksShip", "twoDecksShip", "oneDecksShip"};
    std::vector<ShipData> shipsData;

    std::string path = std::move(pathToJson);
    std::ifstream f(path);
    if(f.is_open()) {
        Json::Value root;
        f >> root;

        Json::Value gamelevelObj = root["gamelevel"];
        level = gamelevelObj["level"].asInt();
        
        Json::Value fieldObj = gamelevelObj["field"];
        int rows = fieldObj["rows"].asInt();
        int columns = fieldObj["columns"].asInt();
        int rowWidth = fieldObj["rowWidth"].asInt();
        int rowHight = fieldObj["rowHight"].asInt();
        fieldData = {rows, columns, static_cast<float>(rowWidth), static_cast<float>(rowHight)};
        
        auto setShipData = [&](const std::string& str) {
            Json::Value decksShipObj = gamelevelObj[str];
            int decks = decksShipObj["decks"].asInt();
            int beginRowCell = decksShipObj["beginRowCell"].asInt();
            int beginColumnCell = decksShipObj["beginColumnCell"].asInt();
            bool isHorizontal = decksShipObj["isHorizontal"].asBool(); 
          
            ShipData shipData = {decks, beginRowCell, beginColumnCell, isHorizontal};
            shipsData.push_back(shipData);
        };
        std::for_each (typeDecksShip.cbegin(), typeDecksShip.cend(), setShipData);
    }
 
    return {level, fieldData, shipsData};
}

std::tuple<int, FieldData, std::vector<ShipData>> ParserJson::parseTxt(const std::string& strData) {
    std::string s = std::move(strData);
    
    FieldData fieldData;
    int n = 0;
    std::vector<ShipData> ships; 
    return std::tuple<int, FieldData, std::vector<ShipData>>{n, fieldData, ships};
}


void ParserJson::parseAlgorithm(const std::string& stringToParse, 
                            const std::string& delimeter, std::queue<std::string>& returnParsedData) {
}
