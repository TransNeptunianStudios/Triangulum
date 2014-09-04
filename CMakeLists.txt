cmake_minimum_required(VERSION 2.8)

project(SpaceShooter)

add_executable(SpaceShooter src/main.cpp)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(SpaceShooter ${SDL2_LIBRARY})