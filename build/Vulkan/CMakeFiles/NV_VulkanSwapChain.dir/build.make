# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = C:\Users\jonas\Documents\Vulkan\examples\imgui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jonas\Documents\Vulkan\examples\imgui\build

# Include any dependencies generated for this target.
include Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/compiler_depend.make

# Include the progress variables for this target.
include Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/progress.make

# Include the compile flags for this target's objects.
include Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/flags.make

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/flags.make
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/includes_CXX.rsp
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.cxx
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jonas\Documents\Vulkan\examples\imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -MD -MT Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch -MF CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.gch.d -o CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.gch -c C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan\CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.cxx

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.i"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -E C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan\CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.cxx > CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.i

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.s"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -x c++-header -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -S C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan\CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.cxx -o CMakeFiles\NV_VulkanSwapChain.dir\cmake_pch.hxx.s

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/flags.make
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/includes_CXX.rsp
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: ../Vulkan/NV_VulkanSwapChain.cpp
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\jonas\Documents\Vulkan\examples\imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -MD -MT Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj -MF CMakeFiles\NV_VulkanSwapChain.dir\NV_VulkanSwapChain.cpp.obj.d -o CMakeFiles\NV_VulkanSwapChain.dir\NV_VulkanSwapChain.cpp.obj -c C:\Users\jonas\Documents\Vulkan\examples\imgui\Vulkan\NV_VulkanSwapChain.cpp

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.i"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -E C:\Users\jonas\Documents\Vulkan\examples\imgui\Vulkan\NV_VulkanSwapChain.cpp > CMakeFiles\NV_VulkanSwapChain.dir\NV_VulkanSwapChain.cpp.i

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.s"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -Winvalid-pch -include C:/Users/jonas/Documents/Vulkan/examples/imgui/build/Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx -S C:\Users\jonas\Documents\Vulkan\examples\imgui\Vulkan\NV_VulkanSwapChain.cpp -o CMakeFiles\NV_VulkanSwapChain.dir\NV_VulkanSwapChain.cpp.s

# Object files for target NV_VulkanSwapChain
NV_VulkanSwapChain_OBJECTS = \
"CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj"

# External object files for target NV_VulkanSwapChain
NV_VulkanSwapChain_EXTERNAL_OBJECTS =

Vulkan/libNV_VulkanSwapChain.a: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/cmake_pch.hxx.gch
Vulkan/libNV_VulkanSwapChain.a: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/NV_VulkanSwapChain.cpp.obj
Vulkan/libNV_VulkanSwapChain.a: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/build.make
Vulkan/libNV_VulkanSwapChain.a: Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\jonas\Documents\Vulkan\examples\imgui\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libNV_VulkanSwapChain.a"
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && $(CMAKE_COMMAND) -P CMakeFiles\NV_VulkanSwapChain.dir\cmake_clean_target.cmake
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NV_VulkanSwapChain.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/build: Vulkan/libNV_VulkanSwapChain.a
.PHONY : Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/build

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/clean:
	cd /d C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan && $(CMAKE_COMMAND) -P CMakeFiles\NV_VulkanSwapChain.dir\cmake_clean.cmake
.PHONY : Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/clean

Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jonas\Documents\Vulkan\examples\imgui C:\Users\jonas\Documents\Vulkan\examples\imgui\Vulkan C:\Users\jonas\Documents\Vulkan\examples\imgui\build C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan C:\Users\jonas\Documents\Vulkan\examples\imgui\build\Vulkan\CMakeFiles\NV_VulkanSwapChain.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Vulkan/CMakeFiles/NV_VulkanSwapChain.dir/depend

