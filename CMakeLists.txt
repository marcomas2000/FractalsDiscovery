cmake_minimum_required(VERSION 3.5)

project(FractalsDiscovery VERSION 0.1 LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(main)
add_subdirectory(gui)
add_subdirectory(creators)

target_include_directories(creators PUBLIC main creators/common creators/experiments/bifurcation creators/experiments/universality)
target_include_directories(gui PUBLIC main gui/common gui/experiments )
