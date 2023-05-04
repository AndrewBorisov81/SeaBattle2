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
       Json::Value fourDecksShipObj = gamelevelObj["fourDecksShip"];

       int level = gamelevelObj["level"].asInt();
       int decks = fourDecksShipObj["decks"].asInt();
       int beginRowCell = fourDecksShipObj["beginRowCell"].asInt();
       int beginColumnCell = fourDecksShipObj["beginColumnCell"].asInt();
       bool isHorizontal = fourDecksShipObj["isHorizontal"].asBool();
       bool stop = true;
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
