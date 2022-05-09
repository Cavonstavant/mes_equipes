# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Lucas/delivery/Tek2/Teams/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Lucas/delivery/Tek2/Teams/Project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Lucas/delivery/Tek2/Teams/Project/CMakeFiles /home/Lucas/delivery/Tek2/Teams/Project/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/Lucas/delivery/Tek2/Teams/Project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named fclean

# Build rule for target.
fclean: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fclean
.PHONY : fclean

# fast build rule for target.
fclean/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/fclean.dir/build.make CMakeFiles/fclean.dir/build
.PHONY : fclean/fast

#=============================================================================
# Target rules for targets named re

# Build rule for target.
re: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 re
.PHONY : re

# fast build rule for target.
re/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/re.dir/build.make CMakeFiles/re.dir/build
.PHONY : re/fast

#=============================================================================
# Target rules for targets named myteams_objects

# Build rule for target.
myteams_objects: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 myteams_objects
.PHONY : myteams_objects

# fast build rule for target.
myteams_objects/fast:
	$(MAKE) $(MAKESILENT) -f objects/src/CMakeFiles/myteams_objects.dir/build.make objects/src/CMakeFiles/myteams_objects.dir/build
.PHONY : myteams_objects/fast

#=============================================================================
# Target rules for targets named myteams_cli

# Build rule for target.
myteams_cli: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 myteams_cli
.PHONY : myteams_cli

# fast build rule for target.
myteams_cli/fast:
	$(MAKE) $(MAKESILENT) -f client/src/CMakeFiles/myteams_cli.dir/build.make client/src/CMakeFiles/myteams_cli.dir/build
.PHONY : myteams_cli/fast

#=============================================================================
# Target rules for targets named myteams_server

# Build rule for target.
myteams_server: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 myteams_server
.PHONY : myteams_server

# fast build rule for target.
myteams_server/fast:
	$(MAKE) $(MAKESILENT) -f server/src/CMakeFiles/myteams_server.dir/build.make server/src/CMakeFiles/myteams_server.dir/build
.PHONY : myteams_server/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... fclean"
	@echo "... re"
	@echo "... myteams_cli"
	@echo "... myteams_objects"
	@echo "... myteams_server"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

