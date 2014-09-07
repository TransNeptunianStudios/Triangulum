cmake_minimum_required(VERSION 2.8)

project(SpaceShooter)

add_executable(
   SpaceShooter
   src/main.cpp
   include/Actor.h
   src/Actor.cpp
   include/Game.h
   src/Game.cpp
   include/KeyHandler.h
   src/KeyHandler.cpp
   include/components/Component.h
   src/components/Component.cpp
   include/components/Motion.h
   src/components/Motion.cpp
   include/components/PlayerMotionControl.h
   src/components/PlayerMotionControl.cpp
   include/components/Position.h
   src/components/Position.cpp
   include/systems/MovementSystem.h
   src/systems/MovementSystem.cpp
   include/systems/PlayerControlSystem.h
   src/systems/PlayerControlSystem.cpp
)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(include ${SDL2_INCLUDE_DIR})
include_directories(include ${OPENGL_INCLUDE_DIR})

target_link_libraries(SpaceShooter 
				${SDL2_LIBRARY}
				${OPENGL_LIBRARIES})
