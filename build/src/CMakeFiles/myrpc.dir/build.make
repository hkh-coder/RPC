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
include src/CMakeFiles/myrpc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/myrpc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/myrpc.dir/flags.make

src/CMakeFiles/myrpc.dir/RpcClient.cpp.o: src/CMakeFiles/myrpc.dir/flags.make
src/CMakeFiles/myrpc.dir/RpcClient.cpp.o: ../src/RpcClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/myrpc.dir/RpcClient.cpp.o"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myrpc.dir/RpcClient.cpp.o -c /home/stu/MyPro/myrpc/src/RpcClient.cpp

src/CMakeFiles/myrpc.dir/RpcClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myrpc.dir/RpcClient.cpp.i"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/src/RpcClient.cpp > CMakeFiles/myrpc.dir/RpcClient.cpp.i

src/CMakeFiles/myrpc.dir/RpcClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myrpc.dir/RpcClient.cpp.s"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/src/RpcClient.cpp -o CMakeFiles/myrpc.dir/RpcClient.cpp.s

src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.o: src/CMakeFiles/myrpc.dir/flags.make
src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.o: ../src/RpcClient.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.o"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myrpc.dir/RpcClient.pb.cc.o -c /home/stu/MyPro/myrpc/src/RpcClient.pb.cc

src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myrpc.dir/RpcClient.pb.cc.i"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/src/RpcClient.pb.cc > CMakeFiles/myrpc.dir/RpcClient.pb.cc.i

src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myrpc.dir/RpcClient.pb.cc.s"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/src/RpcClient.pb.cc -o CMakeFiles/myrpc.dir/RpcClient.pb.cc.s

src/CMakeFiles/myrpc.dir/RpcSer.cpp.o: src/CMakeFiles/myrpc.dir/flags.make
src/CMakeFiles/myrpc.dir/RpcSer.cpp.o: ../src/RpcSer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/myrpc.dir/RpcSer.cpp.o"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myrpc.dir/RpcSer.cpp.o -c /home/stu/MyPro/myrpc/src/RpcSer.cpp

src/CMakeFiles/myrpc.dir/RpcSer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myrpc.dir/RpcSer.cpp.i"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/src/RpcSer.cpp > CMakeFiles/myrpc.dir/RpcSer.cpp.i

src/CMakeFiles/myrpc.dir/RpcSer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myrpc.dir/RpcSer.cpp.s"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/src/RpcSer.cpp -o CMakeFiles/myrpc.dir/RpcSer.cpp.s

src/CMakeFiles/myrpc.dir/localconfig.cpp.o: src/CMakeFiles/myrpc.dir/flags.make
src/CMakeFiles/myrpc.dir/localconfig.cpp.o: ../src/localconfig.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/myrpc.dir/localconfig.cpp.o"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myrpc.dir/localconfig.cpp.o -c /home/stu/MyPro/myrpc/src/localconfig.cpp

src/CMakeFiles/myrpc.dir/localconfig.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myrpc.dir/localconfig.cpp.i"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/src/localconfig.cpp > CMakeFiles/myrpc.dir/localconfig.cpp.i

src/CMakeFiles/myrpc.dir/localconfig.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myrpc.dir/localconfig.cpp.s"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/src/localconfig.cpp -o CMakeFiles/myrpc.dir/localconfig.cpp.s

src/CMakeFiles/myrpc.dir/zookeeper.cpp.o: src/CMakeFiles/myrpc.dir/flags.make
src/CMakeFiles/myrpc.dir/zookeeper.cpp.o: ../src/zookeeper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/myrpc.dir/zookeeper.cpp.o"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myrpc.dir/zookeeper.cpp.o -c /home/stu/MyPro/myrpc/src/zookeeper.cpp

src/CMakeFiles/myrpc.dir/zookeeper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myrpc.dir/zookeeper.cpp.i"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stu/MyPro/myrpc/src/zookeeper.cpp > CMakeFiles/myrpc.dir/zookeeper.cpp.i

src/CMakeFiles/myrpc.dir/zookeeper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myrpc.dir/zookeeper.cpp.s"
	cd /home/stu/MyPro/myrpc/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stu/MyPro/myrpc/src/zookeeper.cpp -o CMakeFiles/myrpc.dir/zookeeper.cpp.s

# Object files for target myrpc
myrpc_OBJECTS = \
"CMakeFiles/myrpc.dir/RpcClient.cpp.o" \
"CMakeFiles/myrpc.dir/RpcClient.pb.cc.o" \
"CMakeFiles/myrpc.dir/RpcSer.cpp.o" \
"CMakeFiles/myrpc.dir/localconfig.cpp.o" \
"CMakeFiles/myrpc.dir/zookeeper.cpp.o"

# External object files for target myrpc
myrpc_EXTERNAL_OBJECTS =

../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/RpcClient.cpp.o
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/RpcClient.pb.cc.o
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/RpcSer.cpp.o
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/localconfig.cpp.o
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/zookeeper.cpp.o
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/build.make
../lib/myrpc/libmyrpc.a: src/CMakeFiles/myrpc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stu/MyPro/myrpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library ../../lib/myrpc/libmyrpc.a"
	cd /home/stu/MyPro/myrpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/myrpc.dir/cmake_clean_target.cmake
	cd /home/stu/MyPro/myrpc/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myrpc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/myrpc.dir/build: ../lib/myrpc/libmyrpc.a

.PHONY : src/CMakeFiles/myrpc.dir/build

src/CMakeFiles/myrpc.dir/clean:
	cd /home/stu/MyPro/myrpc/build/src && $(CMAKE_COMMAND) -P CMakeFiles/myrpc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/myrpc.dir/clean

src/CMakeFiles/myrpc.dir/depend:
	cd /home/stu/MyPro/myrpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stu/MyPro/myrpc /home/stu/MyPro/myrpc/src /home/stu/MyPro/myrpc/build /home/stu/MyPro/myrpc/build/src /home/stu/MyPro/myrpc/build/src/CMakeFiles/myrpc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/myrpc.dir/depend

