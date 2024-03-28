cmake_minimum_required(VERSION 3.19)
project(RaceLib)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_CXX_STANDARD 14)
set(SOURCES Air_vehicles.cpp
        All_terrain_boots.cpp
        Broom.cpp
        Camel.cpp
        Centaur.cpp
        Eagle.cpp
        Fast_camel.cpp
        Land_vehicles.cpp
        Magic_carpet.cpp
        Vehicles.cpp)

set(HEADERS Eagle.h
        Fast_camel.h
        Land_vehicles.h
        Magic_carpet.h
        Vehicles.h
        Air_vehicles.h
        All_terrain_boots.h
        Broom.h
        Camel.h
        Centaur.h)

add_library(RaceLib SHARED ${SOURCES} ${HEADERS})