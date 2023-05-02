#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <tuple>
#include <fstream>

#include "ParserTxt.h"
#include "ParserJson.h"
#include "GameBoard.h"
#include "Model.h"
#include "View.h"
#include "IView.h"
#include "Controller.h"
#include "Subject.h"
#include "ControllerObserver.h"
#include "LoggerObserver.h"
#include "ShipsLogger.h"
#include "ViewObserver.h"
#include "ModelSubject.h"

//#include <nlohmann/json.hpp>
#include <json/json.h>

// Test
#include "InputConsoleController.h"

#include "summer.h"

using namespace std;
//#using json = nlohmann::json;

// how to get and hold data to ship

/*
1;
12, 12, 25, 25;   // rows, columns, rowWidth, rowHight - gameField
4, 1, 1, 0;       // four decks(four horizontal cells from beginCell), beginRowCell, beginColumnCell, isHorizontal - ship1
3, 3, 3, 1;       // three decks - ship2
2, 7, 1, 0;       // ship3
1, 12, 12, 0      // ship4
*/


int main()
{
   cout << "Hello Sea Battle!" << '\n';
   /*json jgamelevel = {
    {"level" , 1},
    {"field", {{"rows", 12}, {"columns", 12}, {"rowWidth", 25}, {"rowHight", 25}}},
    {"fourDecksShip", {{"decks, 4"}, {"beginRowCell", 1}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"threeDecksShip", {{"decks, 3"}, {"beginRowCell", 3}, {"beginColumnCell, 3"}, {"isHorizontal, true"}}},
    {"twoDecksShip", {{"decks, 2"}, {"beginRowCell", 7}, {"beginColumnCell, 1"}, {"isHorizontal, false"}}},
    {"oneDecksShip", {{"decks, 1"}, {"beginRowCell", 12}, {"beginColumnCell, 12"}, {"isHorizontal, false"}}},
   };*/
 
   std::ifstream f("/Users/andrewborisov/Desktop/Dev/Projects/Cpp/VSCode/SeaBattle/levelData.json");
   if(f.is_open()) {
        Json::Value root;
        f >> root;

        Json::Value gamelevelObj = root["gamelevel"];
        Json::Value fourDecksShipObj = gamelevelObj["fourDecksShip"];
        int decks = fourDecksShipObj["decks"].asInt();
        int beginRowCell = fourDecksShipObj["beginRowCell"].asInt();
        int beginColumnCell = fourDecksShipObj["beginColumnCell"].asInt();
        bool isHorizontal = fourDecksShipObj["isHorizontal"].asBool();
        bool stop = true;
        /*json jgameLevel = json::parse(f);
        std::string gameLevelj = jgameLevel.dump();

        ParserJson parserJson;
        std::tuple<int, FieldData, std::vector<ShipData>> levelParsedDataJ = parserJson.parse(gameLevelj);*/
        Json::Value v;
   }

   std::string gameLevel {"1; 12, 12, 25, 25; 4, 0, 0, 0; 3, 1, 2, 1;  2, 7, 1, 0; 1, 11, 11, 0"};
   ParserTxt parser;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedData = parser.parse(gameLevel);
   std::shared_ptr<ISubject> subject = std::make_unique<ModelSubject>();

   enum class InitData{field = 1, ships};
    std::unique_ptr<Model> model = std::make_unique<Model>();
    model->init(std::get<static_cast<int>(InitData::field)>(levelParsedData),  
    std::get<static_cast<int>(InitData::ships)>(levelParsedData));
    model->setSubject(subject);
    std::shared_ptr<IView> view = std::make_shared<View>();

    std::unique_ptr<IObserver> controllerObserver = 
        std::make_unique<ControllerObserver>(subject);
    std::unique_ptr<IObserver> loggerObserver = 
        std::make_unique<LoggerObserver>(subject, std::make_unique<ShipsLogger>());
    std::unique_ptr<IObserver> viewObserver =
        std::make_unique<ViewObserver>(subject, view);

    std::unique_ptr<Controller> controller = 
        std::make_unique<Controller>(std::move(model), view);

    int result = sum(5, 10);

    cout << result << endl;
}
