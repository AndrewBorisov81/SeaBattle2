set(SOURCES
    Cell.cpp
    Controller.cpp
    ControllerObserver.cpp
    GameBoard.cpp
    InputConsoleController.cpp
    LoggerObserver.cpp
    Model.cpp
    ModelSubject.cpp
    Observer.cpp
    Parser.cpp
    Ship.cpp
    ShipsLogger.cpp
    Subject.cpp
    summer.cpp
    View.cpp
    ViewObserver.cpp
)

find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(SeaBattle main.cpp ${SOURCES})

target_link_libraries(SeaBattle PRIVATE nlohmann_json::nlohmann_json)