cmake_minimum_required(VERSION 3.16)

project(testRead VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories for headers (assuming headers are in the same directory as cpp files)
include_directories(${CMAKE_SOURCE_DIR})

# Define the executable target
add_executable(testRead
    testRead.cpp
    sampleset.cpp
    sample.cpp
    determinand.cpp

)

find_package(Threads REQUIRED)
target_link_libraries(testRead Threads::Threads)

set_target_properties(testRead PROPERTIES
    WIN32_EXECUTABLE OFF
    MACOSX_BUNDLE OFF
)