cmake_minimum_required(VERSION 3.10)

project(test_summer_project)

# Add all source files to a variable
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/summer.cpp
    summer_test.cpp
)

# Locate the GoogleTest libraries
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add an executable target called "unit_tests" that links against the GoogleTest library
add_executable(test_summer_project ${SOURCES})

target_link_libraries(test_summer_project ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)