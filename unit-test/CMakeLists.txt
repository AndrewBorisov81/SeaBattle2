cmake_minimum_required(VERSION 3.10)

project(my_project_unit_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# Add all source files to a variable
#set(SOURCES
#    summer_test.cpp
#)

# Locate the GoogleTest libraries
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

# Add an executable target called "unit_tests" that links against the GoogleTest library
#add_executable(my_project_unit_tests ${SOURCES})
#target_link_libraries(my_project_unit_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread summer)

add_subdirectory(TestSummer)
add_subdirectory(TestParser)
#add_subdirectory(TestLoggerObserver)
add_subdirectory(TestTurtle)