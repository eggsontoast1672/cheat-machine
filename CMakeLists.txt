cmake_minimum_required(VERSION 3.5)
project(CheatMachine)

find_package(SFML 2.6 COMPONENTS graphics REQUIRED)

add_executable(cmac src/chess.cpp src/main.cpp)
target_include_directories(cmac PRIVATE include)
target_link_libraries(cmac PRIVATE sfml-graphics)
