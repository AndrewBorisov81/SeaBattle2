# Add all source files to a variable
set(SOURCES
    empty_test.cpp
)

# Locate the GoogleTest libraries
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

set(GMOCK_LIBRARIES /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)

# Add an executable target called "unit_tests" that links against the GoogleTest library
add_executable(test_empty_project ${SOURCES})

target_link_libraries(test_empty_project ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${GMOCK_LIBRARIES} pthread)