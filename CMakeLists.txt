cmake_minimum_required(VERSION 2.8)

project(SpaceShooter)

add_executable(
   SpaceShooter
   src/main.cpp
   include/AnimationFactory.h
   src/AnimationFactory.cpp
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
   include/SoundId.h
   include/ai/FirstBossAi.h
   src/ai/FirstBossAi.cpp
   include/ai/IAi.h
   include/components/Ai.h
   src/components/Ai.cpp
   include/components/Animation.h
   src/components/Animation.cpp
   include/components/Background.h
   src/components/Background.cpp
   include/components/Bullet.h
   src/components/Bullet.cpp
   include/components/DeathSentence.h
   src/components/DeathSentence.cpp
   include/components/Display.h
   src/components/Display.cpp
   include/components/Enemy.h
   src/components/Enemy.cpp
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
   include/graphics/BackgroundView.h
   src/graphics/BackgroundView.cpp
   include/graphics/GameCompMenuView.h
   src/graphics/GameCompMenuView.cpp
   include/graphics/GameOverMenuView.h
   src/graphics/GameOverMenuView.cpp
   include/graphics/IDrawable.h
   include/graphics/PauseMenuView.h
   src/graphics/PauseMenuView.cpp
   include/graphics/LevelCompMenuView.h
   src/graphics/LevelCompMenuView.cpp
   include/graphics/ScoreView.h
   src/graphics/ScoreView.cpp
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
   include/systems/AiControlSystem.h
   src/systems/AiControlSystem.cpp
   include/systems/CollisionSystem.h
   src/systems/CollisionSystem.cpp
   include/systems/DeathRowSystem.h
   src/systems/DeathRowSystem.cpp
   include/systems/Events.h
   include/systems/GunSystem.h
   src/systems/GunSystem.cpp
   include/systems/HudSystem.h
   src/systems/HudSystem.cpp
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
   include/utils/LevelLoader.h
   src/utils/LevelLoader.cpp
   include/utils/Texture.h
   src/utils/Texture.cpp
   include/utils/TextTexture.h
   src/utils/TextTexture.cpp
)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(OpenGL REQUIRED)
find_package(YamlCpp REQUIRED)
find_package(EntityX REQUIRED)

find_package(SFML 2 REQUIRED system window graphics network audio)

include_directories(include ${SDL2_INCLUDE_DIR})
include_directories(include ${SDLIMAGE_INCLUDE_DIR})
include_directories(include ${SDL2TTF_INCLUDE_DIR})
include_directories(include ${OPENGL_INCLUDE_DIR})
include_directories(include ${ENTITYX_INCLUDE_DIR})
include_directories(include ${YAMLCPP_INCLUDE_DIR})

include_directories(include ${SFML_INCLUDE_DIR})

target_link_libraries(SpaceShooter
                        ${SDL2_LIBRARY}
                        ${SDLIMAGE_LIBRARY}
                        ${SDL2TTF_LIBRARY}
                        ${OPENGL_LIBRARIES}
                        ${YAMLCPP_LIBRARY}
                        ${ENTITYX_LIBRARY}
                        ${SFML_LIBRARIES}
)
