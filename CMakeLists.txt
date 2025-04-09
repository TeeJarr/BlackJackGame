cmake_minimum_required(VERSION 3.31.5)
project(Cards LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find raylib
# find_package(raylib REQUIRED)

#Dependencies
include(FetchContent)

# set(RAYLIB_VERSION 4.5.0)
# fetchContent_Declare(
# 	raylib
# 	URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
# 	FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
# )
# set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
# fetchContent_MakeAvailable(raylib)

# Add src directory to include paths
include_directories(src)

# Collect all source files automatically
file(GLOB_RECURSE SOURCES src/*.cpp)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} raylib)
target_include_directories(${PROJECT_NAME} PUBLIC include include/Globals include/Game include/UI include/Cards)

