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
    View.cpp
    ViewObserver.cpp
)

add_library(summer summer.cpp)

add_executable(SeaBattle main.cpp ${SOURCES})

target_link_libraries(SeaBattle PRIVATE summer)