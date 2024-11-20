# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project name
project(can_master)

# Include directory for header files
include_directories(include)

# Add the source files
file(GLOB SOURCES "native/*.cpp")

# Create an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link the Winsock library
target_link_libraries(can_master ws2_32)
