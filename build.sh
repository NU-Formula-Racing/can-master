#!/bin/bash

# Set the build directory
BUILD_DIR="build"

# Check if the first argument is "clean"
if [ "$1" == "--clean" ]; then
  echo "Performing a clean build..."
  
  # If the build directory exists, delete it for a clean build
  if [ -d "$BUILD_DIR" ]; then
    rm -rf $BUILD_DIR
    echo "Previous build directory deleted."
  fi
fi

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to generate Makefiles
cmake .. -G "Unix Makefiles"

# Run make to build the project
make

# Return to the original directory
cd ..

# Print success message
echo "Build complete. Executable is in the $BUILD_DIR directory."
