cmake_minimum_required(VERSION 3.19)
project(racing_simulator_v2)
include_directories(Race_simulator_lib)

set(CMAKE_CXX_STANDARD 14)

add_executable(racing_simulator_v2 main.cpp)
add_subdirectory(Race_simulator_lib)
target_link_libraries(racing_simulator_v2 RaceLib)