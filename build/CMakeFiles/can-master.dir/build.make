# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:/Documents/Code/School/NFR_24-25/can-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:/Documents/Code/School/NFR_24-25/can-master/build

# Include any dependencies generated for this target.
include CMakeFiles/can-master.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/can-master.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/can-master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/can-master.dir/flags.make

CMakeFiles/can-master.dir/native/main.cpp.obj: CMakeFiles/can-master.dir/flags.make
CMakeFiles/can-master.dir/native/main.cpp.obj: CMakeFiles/can-master.dir/includes_CXX.rsp
CMakeFiles/can-master.dir/native/main.cpp.obj: D:/Documents/Code/School/NFR_24-25/can-master/native/main.cpp
CMakeFiles/can-master.dir/native/main.cpp.obj: CMakeFiles/can-master.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:/Documents/Code/School/NFR_24-25/can-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/can-master.dir/native/main.cpp.obj"
	C:/TDM-GCC-64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/can-master.dir/native/main.cpp.obj -MF CMakeFiles/can-master.dir/native/main.cpp.obj.d -o CMakeFiles/can-master.dir/native/main.cpp.obj -c D:/Documents/Code/School/NFR_24-25/can-master/native/main.cpp

CMakeFiles/can-master.dir/native/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/can-master.dir/native/main.cpp.i"
	C:/TDM-GCC-64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:/Documents/Code/School/NFR_24-25/can-master/native/main.cpp > CMakeFiles/can-master.dir/native/main.cpp.i

CMakeFiles/can-master.dir/native/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/can-master.dir/native/main.cpp.s"
	C:/TDM-GCC-64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:/Documents/Code/School/NFR_24-25/can-master/native/main.cpp -o CMakeFiles/can-master.dir/native/main.cpp.s

# Object files for target can-master
can__master_OBJECTS = \
"CMakeFiles/can-master.dir/native/main.cpp.obj"

# External object files for target can-master
can__master_EXTERNAL_OBJECTS =

can-master.exe: CMakeFiles/can-master.dir/native/main.cpp.obj
can-master.exe: CMakeFiles/can-master.dir/build.make
can-master.exe: CMakeFiles/can-master.dir/linkLibs.rsp
can-master.exe: CMakeFiles/can-master.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:/Documents/Code/School/NFR_24-25/can-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable can-master.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/can-master.dir/objects.a
	C:/TDM-GCC-64/bin/ar.exe qc CMakeFiles/can-master.dir/objects.a @CMakeFiles/can-master.dir/objects1.rsp
	C:/TDM-GCC-64/bin/c++.exe -Wl,--whole-archive CMakeFiles/can-master.dir/objects.a -Wl,--no-whole-archive -o can-master.exe -Wl,--out-implib,libcan-master.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/can-master.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/can-master.dir/build: can-master.exe
.PHONY : CMakeFiles/can-master.dir/build

CMakeFiles/can-master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/can-master.dir/cmake_clean.cmake
.PHONY : CMakeFiles/can-master.dir/clean

CMakeFiles/can-master.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" D:/Documents/Code/School/NFR_24-25/can-master D:/Documents/Code/School/NFR_24-25/can-master D:/Documents/Code/School/NFR_24-25/can-master/build D:/Documents/Code/School/NFR_24-25/can-master/build D:/Documents/Code/School/NFR_24-25/can-master/build/CMakeFiles/can-master.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/can-master.dir/depend

