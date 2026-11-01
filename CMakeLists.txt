
cmake_minimum_required(VERSION 3.12)
project(MyRaylibGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------
# LOCAL FIND PACKAGE: Locates raylib instantly from your Arch native paths
# -------------------------------------------------------------------
find_package(raylib CONFIG REQUIRED) # CONFIG mode maps modern targets perfectly

# Declare your engine executable
add_executable(MyRaylibGame src/main.cpp)

# Strict warning policies for your playground code
if(MSVC)
    target_compile_options(MyRaylibGame PRIVATE /W4 /WX)
else()
    target_compile_options(MyRaylibGame PRIVATE -Wall -Wextra -Wpedantic)
endif()

# -------------------------------------------------------------------
# LINKING MECHANICS
# -------------------------------------------------------------------
# This binds to your pacman target, handling includes and linkers instantly!
target_link_libraries(MyRaylibGame PRIVATE raylib)

# Linux driver fail-safes for standard X11 setups
if(UNIX AND NOT APPLE)
    target_link_libraries(MyRaylibGame PRIVATE m pthread dl rt X11)
endif()
