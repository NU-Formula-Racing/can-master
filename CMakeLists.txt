# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(can-master)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directory for header files
include_directories(include)

# Add subdirectory for library
add_subdirectory(lib)

# Add the native main.cpp
add_executable(can-master native/main.cpp)

# Link the library (if applicable)
target_link_libraries(can-master inja-json)
