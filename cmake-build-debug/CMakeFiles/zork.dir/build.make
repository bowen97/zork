# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/lyuru/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/lyuru/.CLion2018.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/zork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zork.dir/flags.make

CMakeFiles/zork.dir/main.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zork.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/main.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/main.cpp"

CMakeFiles/zork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/main.cpp" > CMakeFiles/zork.dir/main.cpp.i

CMakeFiles/zork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/main.cpp" -o CMakeFiles/zork.dir/main.cpp.s

CMakeFiles/zork.dir/room.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/room.cpp.o: ../room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zork.dir/room.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/room.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/room.cpp"

CMakeFiles/zork.dir/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/room.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/room.cpp" > CMakeFiles/zork.dir/room.cpp.i

CMakeFiles/zork.dir/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/room.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/room.cpp" -o CMakeFiles/zork.dir/room.cpp.s

CMakeFiles/zork.dir/trigger.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/trigger.cpp.o: ../trigger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zork.dir/trigger.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/trigger.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/trigger.cpp"

CMakeFiles/zork.dir/trigger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/trigger.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/trigger.cpp" > CMakeFiles/zork.dir/trigger.cpp.i

CMakeFiles/zork.dir/trigger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/trigger.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/trigger.cpp" -o CMakeFiles/zork.dir/trigger.cpp.s

CMakeFiles/zork.dir/item.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/item.cpp.o: ../item.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zork.dir/item.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/item.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/item.cpp"

CMakeFiles/zork.dir/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/item.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/item.cpp" > CMakeFiles/zork.dir/item.cpp.i

CMakeFiles/zork.dir/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/item.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/item.cpp" -o CMakeFiles/zork.dir/item.cpp.s

CMakeFiles/zork.dir/container.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/container.cpp.o: ../container.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zork.dir/container.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/container.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/container.cpp"

CMakeFiles/zork.dir/container.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/container.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/container.cpp" > CMakeFiles/zork.dir/container.cpp.i

CMakeFiles/zork.dir/container.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/container.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/container.cpp" -o CMakeFiles/zork.dir/container.cpp.s

CMakeFiles/zork.dir/creature.cpp.o: CMakeFiles/zork.dir/flags.make
CMakeFiles/zork.dir/creature.cpp.o: ../creature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zork.dir/creature.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zork.dir/creature.cpp.o -c "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/creature.cpp"

CMakeFiles/zork.dir/creature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zork.dir/creature.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/creature.cpp" > CMakeFiles/zork.dir/creature.cpp.i

CMakeFiles/zork.dir/creature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zork.dir/creature.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/creature.cpp" -o CMakeFiles/zork.dir/creature.cpp.s

# Object files for target zork
zork_OBJECTS = \
"CMakeFiles/zork.dir/main.cpp.o" \
"CMakeFiles/zork.dir/room.cpp.o" \
"CMakeFiles/zork.dir/trigger.cpp.o" \
"CMakeFiles/zork.dir/item.cpp.o" \
"CMakeFiles/zork.dir/container.cpp.o" \
"CMakeFiles/zork.dir/creature.cpp.o"

# External object files for target zork
zork_EXTERNAL_OBJECTS =

zork.exe: CMakeFiles/zork.dir/main.cpp.o
zork.exe: CMakeFiles/zork.dir/room.cpp.o
zork.exe: CMakeFiles/zork.dir/trigger.cpp.o
zork.exe: CMakeFiles/zork.dir/item.cpp.o
zork.exe: CMakeFiles/zork.dir/container.cpp.o
zork.exe: CMakeFiles/zork.dir/creature.cpp.o
zork.exe: CMakeFiles/zork.dir/build.make
zork.exe: CMakeFiles/zork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable zork.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zork.dir/build: zork.exe

.PHONY : CMakeFiles/zork.dir/build

CMakeFiles/zork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zork.dir/clean

CMakeFiles/zork.dir/depend:
	cd "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork" "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork" "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug" "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug" "/cygdrive/c/Users/lyuru/Desktop/ece 30862/zork/cmake-build-debug/CMakeFiles/zork.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zork.dir/depend

