cmake_minimum_required(VERSION 3.25.2)

project(my_project)

set(CMAKE_CXX_STANDARD 17)

# Add the "src" directory to the include path
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the "src" directory as a subdirectory
add_subdirectory(src)

# Add the "unit-test" directory as a subdirectory
add_subdirectory(unit-test)