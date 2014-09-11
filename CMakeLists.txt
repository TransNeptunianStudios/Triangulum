cmake_minimum_required(VERSION 2.8)

project(SpaceShooter)

add_executable(
   SpaceShooter
   src/main.cpp
   include/EntityCreator.h
   src/EntityCreator.cpp
   include/Game.h
   src/Game.cpp
   include/KeyHandler.h
   src/KeyHandler.cpp
   include/components/Animation.h
   src/components/Animation.cpp
   include/components/Display.h
   src/components/Display.cpp
   include/components/Gun.h
   src/components/Gun.cpp
   include/components/Motion.h
   src/components/Motion.cpp
   include/components/Position.h
   src/components/Position.cpp
   include/components/PlayerMotionControl.h
   src/components/PlayerMotionControl.cpp
   include/graphics/IAnimatible.h
   include/graphics/IDrawable.h
   include/graphics/BulletView.h
   src/graphics/BulletView.cpp
   include/graphics/SpaceShipView.h
   src/graphics/SpaceShipView.cpp
   include/systems/AnimationSystem.h
   src/systems/AnimationSystem.cpp
   include/systems/GunSystem.h
   src/systems/GunSystem.cpp
   include/systems/MovementSystem.h
   src/systems/MovementSystem.cpp
   include/systems/RenderSystem.h
   src/systems/RenderSystem.cpp
   include/systems/PlayerControlSystem.h
   src/systems/PlayerControlSystem.cpp
   include/utils/Vector2.h
   src/utils/Vector2.cpp
)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(EntityX)

include_directories(include ${SDL2_INCLUDE_DIR})
include_directories(include ${OPENGL_INCLUDE_DIR})
include_directories(include ${ENTITYX_INCLUDE_DIR})

target_link_libraries(SpaceShooter
                        ${SDL2_LIBRARY}
                        ${OPENGL_LIBRARIES}
                        ${ENTITYX_LIBRARY}
)
