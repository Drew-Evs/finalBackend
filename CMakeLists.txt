cmake_minimum_required(VERSION 3.16)

project(test_page VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories for headers (assuming headers are in the same directory as cpp files)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(test_page
    testRead.cpp
    sampleset.cpp      
    sample.cpp         
    determinand.cpp  
)

target_link_libraries(testRead)

set_target_properties(test_page PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE OFF
)