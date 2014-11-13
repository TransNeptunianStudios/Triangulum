cmake_minimum_required(VERSION 2.8)

project(Triangulum)

add_executable(
   Triangulum
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
   include/ResourcePath.hpp
   src/ResourcePath.cpp
   include/ScreenSize.h
   src/ScreenSize.cpp
   include/SoundId.h
   include/ai/FirstBossAi.h
   src/ai/FirstBossAi.cpp
   include/ai/IAi.h
   include/ai/ShootAtPlayerAi.h
   src/ai/ShootAtPlayerAi.cpp
   include/ai/ShootAtPlayerWhenNearAi.h
   src/ai/ShootAtPlayerWhenNearAi.cpp     
   include/components/AbstractMenu.h
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
   include/graphics/FontRepository.h
   src/graphics/FontRepository.cpp
   include/graphics/GameCompMenuView.h
   src/graphics/GameCompMenuView.cpp
   include/graphics/PauseMenuView.h
   src/graphics/PauseMenuView.cpp
   include/graphics/LevelCompMenuView.h
   src/graphics/LevelCompMenuView.cpp
   include/graphics/ScoreView.h
   src/graphics/ScoreView.cpp
   include/graphics/SettingsMenuView.h
   src/graphics/SettingsMenuView.cpp
   include/graphics/StartMenuView.h
   src/graphics/StartMenuView.cpp
   include/graphics/SplashScreen.h
   src/graphics/SplashScreen.cpp
   include/Release.h
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
   include/utils/HighScoreManager.h
   src/utils/HighScoreManager.cpp
   include/utils/LevelLoader.h
   src/utils/LevelLoader.cpp
   include/utils/TMath.h
   src/utils/Math.cpp
)

add_definitions(-std=c++11 -Wl,-Rbin.)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")


#set(CMAKE_FIND_FRAMEWORK NEVER)

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(YAMLCPP_STATIC_LIBRARY TRUE)
	set(SFML_STATIC_LIBRARIES TRUE)
    endif()

find_package(YamlCpp REQUIRED)
find_package(EntityX REQUIRED)
find_package(SFML 2 REQUIRED audio graphics window system network)


include_directories(include ${ENTITYX_INCLUDE_DIR})
include_directories(include ${YAMLCPP_INCLUDE_DIR})
include_directories(include ${SFML_INCLUDE_DIR})

target_link_libraries(Triangulum
                        ${YAMLCPP_LIBRARY}
                        ${ENTITYX_LIBRARY}
                        ${SFML_LIBRARIES}
)
