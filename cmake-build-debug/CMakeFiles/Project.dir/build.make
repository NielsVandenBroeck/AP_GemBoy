# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Project.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project.dir/flags.make

CMakeFiles/Project.dir/src/main.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/main.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/main.cpp"

CMakeFiles/Project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/main.cpp" > CMakeFiles/Project.dir/src/main.cpp.i

CMakeFiles/Project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/main.cpp" -o CMakeFiles/Project.dir/src/main.cpp.s

CMakeFiles/Project.dir/src/Representation/Game.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/Representation/Game.cpp.o: ../src/Representation/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project.dir/src/Representation/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/Representation/Game.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/Game.cpp"

CMakeFiles/Project.dir/src/Representation/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/Representation/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/Game.cpp" > CMakeFiles/Project.dir/src/Representation/Game.cpp.i

CMakeFiles/Project.dir/src/Representation/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/Representation/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/Game.cpp" -o CMakeFiles/Project.dir/src/Representation/Game.cpp.s

CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o: ../src/Representation/StateManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/StateManager.cpp"

CMakeFiles/Project.dir/src/Representation/StateManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/Representation/StateManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/StateManager.cpp" > CMakeFiles/Project.dir/src/Representation/StateManager.cpp.i

CMakeFiles/Project.dir/src/Representation/StateManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/Representation/StateManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/StateManager.cpp" -o CMakeFiles/Project.dir/src/Representation/StateManager.cpp.s

CMakeFiles/Project.dir/src/Representation/State.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/Representation/State.cpp.o: ../src/Representation/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project.dir/src/Representation/State.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/Representation/State.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/State.cpp"

CMakeFiles/Project.dir/src/Representation/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/Representation/State.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/State.cpp" > CMakeFiles/Project.dir/src/Representation/State.cpp.i

CMakeFiles/Project.dir/src/Representation/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/Representation/State.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/State.cpp" -o CMakeFiles/Project.dir/src/Representation/State.cpp.s

CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o: ../src/Representation/ConcreteFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/ConcreteFactory.cpp"

CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/ConcreteFactory.cpp" > CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.i

CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/ConcreteFactory.cpp" -o CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.s

CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o: CMakeFiles/Project.dir/flags.make
CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o: ../src/Representation/RepresentationEntity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o -c "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/RepresentationEntity.cpp"

CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/RepresentationEntity.cpp" > CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.i

CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/src/Representation/RepresentationEntity.cpp" -o CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.s

# Object files for target Project
Project_OBJECTS = \
"CMakeFiles/Project.dir/src/main.cpp.o" \
"CMakeFiles/Project.dir/src/Representation/Game.cpp.o" \
"CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o" \
"CMakeFiles/Project.dir/src/Representation/State.cpp.o" \
"CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o" \
"CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o"

# External object files for target Project
Project_EXTERNAL_OBJECTS =

Project: CMakeFiles/Project.dir/src/main.cpp.o
Project: CMakeFiles/Project.dir/src/Representation/Game.cpp.o
Project: CMakeFiles/Project.dir/src/Representation/StateManager.cpp.o
Project: CMakeFiles/Project.dir/src/Representation/State.cpp.o
Project: CMakeFiles/Project.dir/src/Representation/ConcreteFactory.cpp.o
Project: CMakeFiles/Project.dir/src/Representation/RepresentationEntity.cpp.o
Project: CMakeFiles/Project.dir/build.make
Project: libLogic.a
Project: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Project: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Project: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Project: CMakeFiles/Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project.dir/build: Project
.PHONY : CMakeFiles/Project.dir/build

CMakeFiles/Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project.dir/clean

CMakeFiles/Project.dir/depend:
	cd "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project" "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project" "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug" "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug" "/mnt/c/Users/niels/OneDrive - Universiteit Antwerpen/School 2022-2023/AP/Project/cmake-build-debug/CMakeFiles/Project.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Project.dir/depend

