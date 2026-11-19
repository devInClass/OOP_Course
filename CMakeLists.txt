cmake_minimum_required(VERSION 3.14)
project(Class1 CXX)

# 1. Create the executable FIRST
#add_executable(Class1 src/main.cpp "include/Actor.h" "src/Actor.cpp")

# Automatically grab all .cpp files in the src folder
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Class1 ${SOURCES})

# 2. Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Tell CMake to look in the 'include' folder
target_include_directories(Class1 PRIVATE include)

# 4. Fetch raylib
include(FetchContent)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/6.2.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# 5. Link raylib
target_link_libraries(Class1 PRIVATE raylib)