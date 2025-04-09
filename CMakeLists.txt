cmake_minimum_required(VERSION 3.5)
project(CheatMachine)

find_package(SDL3 REQUIRED)

add_executable(cmac src/chess.cpp src/main.cpp src/window.cpp)
target_include_directories(cmac PRIVATE include)
target_link_libraries(cmac PRIVATE SDL3::SDL3)
