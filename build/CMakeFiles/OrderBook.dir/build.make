# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\order_book

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\order_book\build

# Include any dependencies generated for this target.
include CMakeFiles/OrderBook.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OrderBook.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OrderBook.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OrderBook.dir/flags.make

CMakeFiles/OrderBook.dir/main.cpp.obj: CMakeFiles/OrderBook.dir/flags.make
CMakeFiles/OrderBook.dir/main.cpp.obj: D:/order_book/main.cpp
CMakeFiles/OrderBook.dir/main.cpp.obj: CMakeFiles/OrderBook.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\order_book\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OrderBook.dir/main.cpp.obj"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OrderBook.dir/main.cpp.obj -MF CMakeFiles\OrderBook.dir\main.cpp.obj.d -o CMakeFiles\OrderBook.dir\main.cpp.obj -c D:\order_book\main.cpp

CMakeFiles/OrderBook.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OrderBook.dir/main.cpp.i"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\order_book\main.cpp > CMakeFiles\OrderBook.dir\main.cpp.i

CMakeFiles/OrderBook.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OrderBook.dir/main.cpp.s"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\order_book\main.cpp -o CMakeFiles\OrderBook.dir\main.cpp.s

CMakeFiles/OrderBook.dir/order.cpp.obj: CMakeFiles/OrderBook.dir/flags.make
CMakeFiles/OrderBook.dir/order.cpp.obj: D:/order_book/order.cpp
CMakeFiles/OrderBook.dir/order.cpp.obj: CMakeFiles/OrderBook.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\order_book\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OrderBook.dir/order.cpp.obj"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OrderBook.dir/order.cpp.obj -MF CMakeFiles\OrderBook.dir\order.cpp.obj.d -o CMakeFiles\OrderBook.dir\order.cpp.obj -c D:\order_book\order.cpp

CMakeFiles/OrderBook.dir/order.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OrderBook.dir/order.cpp.i"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\order_book\order.cpp > CMakeFiles\OrderBook.dir\order.cpp.i

CMakeFiles/OrderBook.dir/order.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OrderBook.dir/order.cpp.s"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\order_book\order.cpp -o CMakeFiles\OrderBook.dir\order.cpp.s

CMakeFiles/OrderBook.dir/order_book.cpp.obj: CMakeFiles/OrderBook.dir/flags.make
CMakeFiles/OrderBook.dir/order_book.cpp.obj: D:/order_book/order_book.cpp
CMakeFiles/OrderBook.dir/order_book.cpp.obj: CMakeFiles/OrderBook.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\order_book\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OrderBook.dir/order_book.cpp.obj"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OrderBook.dir/order_book.cpp.obj -MF CMakeFiles\OrderBook.dir\order_book.cpp.obj.d -o CMakeFiles\OrderBook.dir\order_book.cpp.obj -c D:\order_book\order_book.cpp

CMakeFiles/OrderBook.dir/order_book.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OrderBook.dir/order_book.cpp.i"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\order_book\order_book.cpp > CMakeFiles\OrderBook.dir\order_book.cpp.i

CMakeFiles/OrderBook.dir/order_book.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OrderBook.dir/order_book.cpp.s"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\order_book\order_book.cpp -o CMakeFiles\OrderBook.dir\order_book.cpp.s

CMakeFiles/OrderBook.dir/trade.cpp.obj: CMakeFiles/OrderBook.dir/flags.make
CMakeFiles/OrderBook.dir/trade.cpp.obj: D:/order_book/trade.cpp
CMakeFiles/OrderBook.dir/trade.cpp.obj: CMakeFiles/OrderBook.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\order_book\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OrderBook.dir/trade.cpp.obj"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OrderBook.dir/trade.cpp.obj -MF CMakeFiles\OrderBook.dir\trade.cpp.obj.d -o CMakeFiles\OrderBook.dir\trade.cpp.obj -c D:\order_book\trade.cpp

CMakeFiles/OrderBook.dir/trade.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OrderBook.dir/trade.cpp.i"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\order_book\trade.cpp > CMakeFiles\OrderBook.dir\trade.cpp.i

CMakeFiles/OrderBook.dir/trade.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OrderBook.dir/trade.cpp.s"
	D:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\order_book\trade.cpp -o CMakeFiles\OrderBook.dir\trade.cpp.s

# Object files for target OrderBook
OrderBook_OBJECTS = \
"CMakeFiles/OrderBook.dir/main.cpp.obj" \
"CMakeFiles/OrderBook.dir/order.cpp.obj" \
"CMakeFiles/OrderBook.dir/order_book.cpp.obj" \
"CMakeFiles/OrderBook.dir/trade.cpp.obj"

# External object files for target OrderBook
OrderBook_EXTERNAL_OBJECTS =

OrderBook.exe: CMakeFiles/OrderBook.dir/main.cpp.obj
OrderBook.exe: CMakeFiles/OrderBook.dir/order.cpp.obj
OrderBook.exe: CMakeFiles/OrderBook.dir/order_book.cpp.obj
OrderBook.exe: CMakeFiles/OrderBook.dir/trade.cpp.obj
OrderBook.exe: CMakeFiles/OrderBook.dir/build.make
OrderBook.exe: CMakeFiles/OrderBook.dir/linkLibs.rsp
OrderBook.exe: CMakeFiles/OrderBook.dir/objects1.rsp
OrderBook.exe: CMakeFiles/OrderBook.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\order_book\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable OrderBook.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OrderBook.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OrderBook.dir/build: OrderBook.exe
.PHONY : CMakeFiles/OrderBook.dir/build

CMakeFiles/OrderBook.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OrderBook.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OrderBook.dir/clean

CMakeFiles/OrderBook.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\order_book D:\order_book D:\order_book\build D:\order_book\build D:\order_book\build\CMakeFiles\OrderBook.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OrderBook.dir/depend

