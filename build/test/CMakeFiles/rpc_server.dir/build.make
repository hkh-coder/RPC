# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stu/MyPro/myrpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stu/MyPro/myrpc/build

# Include any dependencies generated for this target.
include test/CMakeFiles/rpc_server.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/rpc_server.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/rpc_server.dir/flags.make

test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.o: test/CMakeFiles/rpc_server.dir/flags.make
test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.o: ../test/testrpcserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.o"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc_server.dir/testrpcserver.cpp.o -c /home/stu/MyPro/myrpc/test/testrpcserver.cpp

test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc_server.dir/testrpcserver.cpp.i"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/test/testrpcserver.cpp > CMakeFiles/rpc_server.dir/testrpcserver.cpp.i

test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc_server.dir/testrpcserver.cpp.s"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/test/testrpcserver.cpp -o CMakeFiles/rpc_server.dir/testrpcserver.cpp.s

test/CMakeFiles/rpc_server.dir/Message.pb.cc.o: test/CMakeFiles/rpc_server.dir/flags.make
test/CMakeFiles/rpc_server.dir/Message.pb.cc.o: ../test/Message.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/rpc_server.dir/Message.pb.cc.o"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rpc_server.dir/Message.pb.cc.o -c /home/stu/MyPro/myrpc/test/Message.pb.cc

test/CMakeFiles/rpc_server.dir/Message.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rpc_server.dir/Message.pb.cc.i"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/test/Message.pb.cc > CMakeFiles/rpc_server.dir/Message.pb.cc.i

test/CMakeFiles/rpc_server.dir/Message.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rpc_server.dir/Message.pb.cc.s"
	cd /home/stu/MyPro/myrpc/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/test/Message.pb.cc -o CMakeFiles/rpc_server.dir/Message.pb.cc.s

# Object files for target rpc_server
rpc_server_OBJECTS = \
"CMakeFiles/rpc_server.dir/testrpcserver.cpp.o" \
"CMakeFiles/rpc_server.dir/Message.pb.cc.o"

# External object files for target rpc_server
rpc_server_EXTERNAL_OBJECTS =

../bin/rpc_server: test/CMakeFiles/rpc_server.dir/testrpcserver.cpp.o
../bin/rpc_server: test/CMakeFiles/rpc_server.dir/Message.pb.cc.o
../bin/rpc_server: test/CMakeFiles/rpc_server.dir/build.make
../bin/rpc_server: ../lib/myrpc/libmyrpc.a
../bin/rpc_server: ../lib/tinyxml/libtinyxml.so
../bin/rpc_server: test/CMakeFiles/rpc_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/rpc_server"
	cd /home/stu/MyPro/myrpc/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/rpc_server.dir/build: ../bin/rpc_server

.PHONY : test/CMakeFiles/rpc_server.dir/build

test/CMakeFiles/rpc_server.dir/clean:
	cd /home/stu/MyPro/myrpc/build/test && $(CMAKE_COMMAND) -P CMakeFiles/rpc_server.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/rpc_server.dir/clean

test/CMakeFiles/rpc_server.dir/depend:
	cd /home/stu/MyPro/myrpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stu/MyPro/myrpc /home/stu/MyPro/myrpc/test /home/stu/MyPro/myrpc/build /home/stu/MyPro/myrpc/build/test /home/stu/MyPro/myrpc/build/test/CMakeFiles/rpc_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/rpc_server.dir/depend

