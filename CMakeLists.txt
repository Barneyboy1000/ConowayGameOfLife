
cmake_minimum_required(VERSION 3.12)

project(ConwaysGameOfLife)

add_executable(conway
    source/Application.cpp
    source/Application.h
    source/CellularGrid.cpp
    source/CellularGrid.h
    source/GameOfLife.cpp
    source/GameOfLife.h
    source/main.cpp
    README.md
)

target_compile_features(conway PRIVATE cxx_std_17)
