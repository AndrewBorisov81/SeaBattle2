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

add_executable(SeaBattle main.cpp ${SOURCES})