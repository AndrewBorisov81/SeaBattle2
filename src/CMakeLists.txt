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
    ParserTxt.cpp
    ParserJson.cpp
    Ship.cpp
    ShipsLogger.cpp
    Subject.cpp
    summer.cpp
    View.cpp
    ViewObserver.cpp
)

find_package(PkgConfig REQUIRED)
pkg_search_module(JSONCPP jsoncpp)
find_package(jsoncpp REQUIRED)

add_executable(SeaBattle main.cpp ${SOURCES})

target_link_libraries(SeaBattle jsoncpp_lib)
