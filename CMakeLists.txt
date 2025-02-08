# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Project name
project(can_master)

# C:\Boost\boost_1_86_0_built\include\boost
# Define Boost paths

set(BOOST_ROOT "C:/Boost/boost_1_86_0_built")
set(BOOST_INCLUDEDIR "C:/Boost/boost_1_86_0_built/include/boost-1_86")
set(BOOST_LIBRARYDIR "C:/Boost/boost_1_86_0_built/")

# CMakeLists.txt
find_package(Boost REQUIRED COMPONENTS filesystem system thread)  # etc.



# Include Boost and websocketpp
include_directories(
    ${BOOST_INCLUDEDIR}       # Boost include directory
    "${CMAKE_SOURCE_DIR}/include"  # Websocketpp include directory
)

# Add the source files
file(GLOB SOURCES "native/*.cpp")

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")

    message(STATUS "Include paths: ${CMAKE_INCLUDE_PATH}")
else()
    message(FATAL_ERROR "Boost not found!")
endif()

# Create an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Boost and Winsock
target_link_libraries(${PROJECT_NAME} ws2_32 ${Boost_LIBRARIES})
