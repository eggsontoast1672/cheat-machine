cmake_minimum_required(VERSION 3.5)
project(CheatMachine)
add_executable(cmac src/chess.cpp src/main.cpp src/window.cpp)
target_include_directories(cmac PRIVATE include)
