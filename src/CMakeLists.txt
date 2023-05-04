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

# Set the binary directory for the jsoncpp library
set(JSONCPP_BINARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp/build/lib")

# Add the jsoncpp library as an imported target
add_library(jsoncpp_lib STATIC IMPORTED)

# Set the location of the jsoncpp library binary file
set_target_properties(jsoncpp_lib PROPERTIES IMPORTED_LOCATION "${JSONCPP_BINARY_DIR}/libjsoncpp.a")

# Add the directory containing the jsoncpp headers to the include paths
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp/include")
set_target_properties(jsoncpp_lib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp/include"
)

add_executable(SeaBattle main.cpp ${SOURCES})

#target_link_libraries(SeaBattle "${JSONCPP_BINARY_DIR}/libjsoncpp.a")
target_link_libraries(SeaBattle jsoncpp_lib)