# Add all source files to a variable
set(SOURCES
    summer.cpp
)

# Add a library target called "summer" that compiles the source files
add_library(summer ${SOURCES})

# Add the unit test executable target
add_executable(main main.cpp)

target_link_libraries(main PRIVATE summer)