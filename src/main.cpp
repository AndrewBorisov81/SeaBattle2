#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <tuple>

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

#include <json/json.h>

#include "summer.h"

using namespace std;

int main()
{
   cout << "Hello Sea Battle!" << '\n';

   std::string jsonPath {"/Users/andrewborisov/Desktop/Dev/Projects/Cpp/VSCode/SeaBattle/levelData.json"};
   ParserJson parserJson;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedDataJ = parserJson.parseJson(jsonPath);

   std::string gameLevel {"1; 12, 12, 25, 25; 4, 0, 0, 0; 3, 1, 2, 1;  2, 7, 1, 0; 1, 11, 11, 0"};
   ParserTxt parser;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedData = parser.parseTxt(gameLevel);
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
