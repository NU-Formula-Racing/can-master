#!bin/bash

rm -rf bin
mkdir bin
cd bin

proj_name=canmaster
proj_root_dir=$(pwd)/../

flags=(
	-std=c++11 -w
)

# Include directories
inc=(
	-I ../include/						# Project Includes
)

# Automatically find C source files in specified directories
src=($(find ../native -type f -name '*.cpp'))

libs=(
	-lkernel32 
	-luser32 
	-lshell32 
	-lgdi32 
    -lWinmm
	-lAdvapi32
)

# Build
build_cmd="g++ -O0 ${inc[*]} ${src[*]} ${flags[*]} ${libs[*]} -lm -o ${proj_name}"

echo "Building..."
echo $build_cmd
$build_cmd

cd ..



