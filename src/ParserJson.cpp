/*json jgamelevel = {
    {"level" , 1},
    {"field", {{"rows", 12}, {"columns", 12}, {"rowWidth", 25}, {"rowHight", 25}}},
    {"fourDecksShip", {{"decks, 4"}, {"beginRowCell", 1}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"threeDecksShip", {{"decks, 3"}, {"beginRowCell", 3}, {"beginColumnCell, 3"}, {"isHorizontal, true"}}},
    {"twoDecksShip", {{"decks, 2"}, {"beginRowCell", 7}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"oneDecksShip", {{"decks, 1"}, {"beginRowCell", 12}, {"beginColumnCell, 12"}, {"isHorizontal, false"}}},
};*/


#include "ParserJson.h"

#include <fstream>
#include <algorithm>

#include <json/json.h>

ParserJson::ParserJson() {

}

std::tuple<int, FieldData, std::vector<ShipData>> ParserJson::parseJson(const std::string& pathToJson) {
    std::string path = std::move(pathToJson);

    //std::ifstream f("/Users/andrewborisov/Desktop/Dev/Projects/Cpp/VSCode/SeaBattle/levelData.json");
    std::ifstream f(path);
    if(f.is_open()) {
        Json::Value root;
        f >> root;

        Json::Value gamelevelObj = root["gamelevel"];
        int level = gamelevelObj["level"].asInt();
        
        Json::Value fieldObj = gamelevelObj["field"];
        int rows = fieldObj["rows"].asInt();
        int columns = fieldObj["columns"].asInt();
        int rowWidth = fieldObj["rowWidth"].asInt();
        int rowHight = fieldObj["rowHight"].asInt();
        FieldData fieldData = {rows, columns, static_cast<float>(rowWidth), static_cast<float>(rowHight)};

        Json::Value decksShipObj = gamelevelObj["fourDecksShip"];
        int decks = decksShipObj["decks"].asInt();
        int beginRowCell = decksShipObj["beginRowCell"].asInt();
        int beginColumnCell = decksShipObj["beginColumnCell"].asInt();
        bool isHorizontal = decksShipObj["isHorizontal"].asBool();

        ShipData shipData = {decks, beginColumnCell, beginColumnCell, isHorizontal};
        
        std::vector<std::string> typeDecksShip = {"fourDecksShip", "threeDecksShip", "twoDecksShip", "oneDecksShip"};

        /*auto setShipData = [&gamelevelObj, &shipData]() {
            Json::Value decksShipObj = gamelevelObj["fourDecksShip"];
            int decks = decksShipObj["decks"].asInt();
            int beginRowCell = decksShipObj["beginRowCell"].asInt();
            int beginColumnCell = decksShipObj["beginColumnCell"].asInt();
            bool isHorizontal = decksShipObj["isHorizontal"].asBool(); 

            shipData = {decks, beginColumnCell, beginColumnCell, isHorizontal};
        };
        std::for_each (typeDecksShip.cbegin(), typeDecksShip.cend(), setShipData);*/
    }

    FieldData fieldData;
    int n = 0;
    std::vector<ShipData> ships; 
    return std::tuple<int, FieldData, std::vector<ShipData>>{n, fieldData, ships};
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
