# Add all source files to a variable
set(SOURCES
    turtle_test.cpp
)

# Locate the GoogleTest libraries
find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GMOCK_INCLUDE_DIRS})

set(GMOCK_LIBRARIES /usr/local/lib/libgmock.a /usr/local/lib/libgmock_main.a)

# Add an executable target called "unit_tests" that links against the GoogleTest library
add_executable(test_turtle_project ${SOURCES})

target_link_libraries(test_turtle_project ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

#target_link_libraries(test_loggerObserver_project 
 #   ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} 
  #  ${GMOCK_LIBRARIES} ${GMOCK_MAIN_LIBRARIES} 
 #   pthread)
