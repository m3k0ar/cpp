# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.16.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.16.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/armand/Documents/cpp/thread_safe_logger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/armand/Documents/cpp/thread_safe_logger/build

# Include any dependencies generated for this target.
include src/CMakeFiles/logger.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/logger.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/logger.dir/flags.make

src/CMakeFiles/logger.dir/empty.cpp.o: src/CMakeFiles/logger.dir/flags.make
src/CMakeFiles/logger.dir/empty.cpp.o: ../src/empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/armand/Documents/cpp/thread_safe_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/logger.dir/empty.cpp.o"
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/logger.dir/empty.cpp.o -c /Users/armand/Documents/cpp/thread_safe_logger/src/empty.cpp

src/CMakeFiles/logger.dir/empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/logger.dir/empty.cpp.i"
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/armand/Documents/cpp/thread_safe_logger/src/empty.cpp > CMakeFiles/logger.dir/empty.cpp.i

src/CMakeFiles/logger.dir/empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/logger.dir/empty.cpp.s"
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/armand/Documents/cpp/thread_safe_logger/src/empty.cpp -o CMakeFiles/logger.dir/empty.cpp.s

# Object files for target logger
logger_OBJECTS = \
"CMakeFiles/logger.dir/empty.cpp.o"

# External object files for target logger
logger_EXTERNAL_OBJECTS =

src/liblogger.a: src/CMakeFiles/logger.dir/empty.cpp.o
src/liblogger.a: src/CMakeFiles/logger.dir/build.make
src/liblogger.a: src/CMakeFiles/logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/armand/Documents/cpp/thread_safe_logger/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblogger.a"
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && $(CMAKE_COMMAND) -P CMakeFiles/logger.dir/cmake_clean_target.cmake
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/logger.dir/build: src/liblogger.a

.PHONY : src/CMakeFiles/logger.dir/build

src/CMakeFiles/logger.dir/clean:
	cd /Users/armand/Documents/cpp/thread_safe_logger/build/src && $(CMAKE_COMMAND) -P CMakeFiles/logger.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/logger.dir/clean

src/CMakeFiles/logger.dir/depend:
	cd /Users/armand/Documents/cpp/thread_safe_logger/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/armand/Documents/cpp/thread_safe_logger /Users/armand/Documents/cpp/thread_safe_logger/src /Users/armand/Documents/cpp/thread_safe_logger/build /Users/armand/Documents/cpp/thread_safe_logger/build/src /Users/armand/Documents/cpp/thread_safe_logger/build/src/CMakeFiles/logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/logger.dir/depend
