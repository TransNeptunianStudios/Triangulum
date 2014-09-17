cmake_minimum_required(VERSION 2.8)

project(SpaceShooter)

add_executable(
   SpaceShooter
   src/main.cpp
   include/AudioManager.h
   src/AudioManager.cpp
   include/EntityCreator.h
   src/EntityCreator.cpp
   include/Game.h
   src/Game.cpp
   include/KeyHandler.h
   src/KeyHandler.cpp
   include/SpriteSheet.h
   src/SpriteSheet.cpp
   include/SoundId.h
   include/components/Animation.h
   src/components/Animation.cpp
   include/components/Bullet.h
   src/components/Bullet.cpp
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
   include/graphics/BackgroundView.h
   src/graphics/BackgroundView.cpp
   include/graphics/BulletView.h
   src/graphics/BulletView.cpp
   include/graphics/SpaceShipView.h
   src/graphics/SpaceShipView.cpp
   include/systems/AnimationSystem.h
   src/systems/AnimationSystem.cpp
   include/systems/AudioSystem.h
   src/systems/AudioSystem.cpp
   include/systems/BulletLifeTimeSystem.h
   src/systems/BulletLifeTimeSystem.cpp
   include/systems/Events.h
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
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(OpenGL REQUIRED)
find_package(EntityX)

include_directories(include ${SDL2_INCLUDE_DIR})
include_directories(include ${SDLIMAGE_INCLUDE_DIR})
include_directories(include ${SDL2_MIXER_INCLUDE_DIRS})
include_directories(include ${OPENGL_INCLUDE_DIR})
include_directories(include ${ENTITYX_INCLUDE_DIR})

target_link_libraries(SpaceShooter
                        ${SDL2_LIBRARY}
                        ${SDLIMAGE_LIBRARY}
                        ${SDL2_MIXER_LIBRARIES}
                        ${OPENGL_LIBRARIES}
                        ${ENTITYX_LIBRARY}                        
)
