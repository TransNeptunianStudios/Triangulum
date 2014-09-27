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
   include/GameManager.h
   src/GameManager.cpp
   include/ICreatable.h
   include/KeyHandler.h
   src/KeyHandler.cpp
   include/ScreenSize.h
   src/ScreenSize.cpp
   include/SpriteSheet.h
   src/SpriteSheet.cpp
   include/Animation.h
   src/Animation.cpp
   include/SoundId.h
   include/components/State.h
   src/components/State.cpp
   include/components/Bullet.h
   src/components/Bullet.cpp
   include/components/Display.h
   src/components/Display.cpp
   include/components/Gun.h
   src/components/Gun.cpp
   include/components/Health.h
   src/components/Health.cpp
   include/components/IMenu.h
   include/components/Menu.h
   src/components/Menu.cpp
   include/components/Motion.h
   src/components/Motion.cpp
   include/components/Obstacle.h
   src/components/Obstacle.cpp
   include/components/Position.h
   src/components/Position.cpp
   include/components/PlayerControl.h
   src/components/PlayerControl.cpp
   include/components/SpaceShip.h
   src/components/SpaceShip.cpp
   include/components/Volume.h
   src/components/Volume.cpp
   include/graphics/IAnimatible.h
   include/graphics/IDrawable.h
   include/graphics/BackgroundView.h
   src/graphics/BackgroundView.cpp
   include/graphics/Asteroidview.h
   src/graphics/Asteroidview.cpp
   include/graphics/BulletView.h
   src/graphics/BulletView.cpp
   include/graphics/GameOverMenuView.h
   src/graphics/GameOverMenuView.cpp
   include/graphics/SpaceShipView.h
   src/graphics/SpaceShipView.cpp
   include/graphics/StartMenuView.h
   src/graphics/StartMenuView.cpp
   include/systems/AnimationSystem.h
   src/systems/AnimationSystem.cpp
   include/systems/AudioSystem.h
   src/systems/AudioSystem.cpp
   include/systems/BulletLifeTimeSystem.h
   src/systems/BulletLifeTimeSystem.cpp
   include/systems/BulletType.h
   src/systems/BulletType.cpp
   include/systems/CollisionSystem.h
   src/systems/CollisionSystem.cpp
   include/systems/Events.h
   include/systems/GunSystem.h
   src/systems/GunSystem.cpp
   include/systems/LevelSystem.h
   src/systems/LevelSystem.cpp
   include/systems/MenuSystem.h
   src/systems/MenuSystem.cpp
   include/systems/MovementSystem.h
   src/systems/MovementSystem.cpp
   include/systems/RenderSystem.h
   src/systems/RenderSystem.cpp
   include/systems/PlayerControlSystem.h
   src/systems/PlayerControlSystem.cpp
   include/utils/CollisionBox.h
   src/utils/CollisionBox.cpp
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
