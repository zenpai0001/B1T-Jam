# 1. Set the minimum required CMake version
cmake_minimum_required(VERSION 3.11)

# 2. Name your project and specify the language (C)
project(MyCProject LANGUAGES C)

# 3. Use the C24 standard
set(CMAKE_COMPILER "tcc")
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

string(REPLACE "-O3" "-O1" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

find_package(raylib CONFIG REQUIRED) # CONFIG mode maps modern targets perfectly


# Enable all warnings based on the compiler
if(CMAKE_C_COMPILER_ID MATCHES "TinyCC")
    add_definitions(-D_DEFAULT_SOURCE)
-endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(my_game PRIVATE m dl pthread rt X11)
    elseif(WIN32)
    target_link_libraries(my_game PRIVATE opengl32 gdl32 winmm)
endif()    

add_subdirectory(vendor/raylib)

add_executable(my_program main.c)

target_link_libraries(MyRaylibGame PRIVATE raylib)


