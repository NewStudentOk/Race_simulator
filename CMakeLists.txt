cmake_minimum_required(VERSION 3.19)
project(racing_simulator_v2)

set(CMAKE_CXX_STANDARD 14)

add_library(RaceLib SHARED Race_simulator_lib/Camel.cpp Race_simulator_lib/Camel.h
        Race_simulator_lib/Fast_camel.cpp Race_simulator_lib/Fast_camel.h
        Race_simulator_lib/Centaur.cpp Race_simulator_lib/Centaur.h
        Race_simulator_lib/All_terrain_boots.cpp Race_simulator_lib/All_terrain_boots.h
        Race_simulator_lib/Magic_carpet.cpp Race_simulator_lib/Magic_carpet.h
        Race_simulator_lib/Eagle.cpp Race_simulator_lib/Eagle.h
        Race_simulator_lib/Broom.cpp Race_simulator_lib/Broom.h
        Race_simulator_lib/Land_vehicles.cpp Race_simulator_lib/Land_vehicles.h
        Race_simulator_lib/Air_vehicles.cpp Race_simulator_lib/Air_vehicles.h
        Race_simulator_lib/Vehicles.cpp Race_simulator_lib/Vehicles.h )

add_executable(racing_simulator_v2 main.cpp)
target_link_libraries(racing_simulator_v2 RaceLib)