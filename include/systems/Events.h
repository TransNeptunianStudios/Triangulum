#ifndef EVENTS_H
#define EVENTS_H

#include "SFML/Window/Keyboard.hpp"
#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "SoundId.h"

struct EvShowStartMenu: public entityx::Event<EvShowStartMenu>
{
   EvShowStartMenu(bool _fade)
     : fade (_fade)
   {
   }

   bool fade;
};

struct EvStartGame : public entityx::Event<EvStartGame>
{
   EvStartGame() {}
};

struct EvQuitGame : public entityx::Event<EvQuitGame>
{
   EvQuitGame() {}
};

struct EvShowSettingsMenu : public entityx::Event<EvShowSettingsMenu>
{
   EvShowSettingsMenu() {}
};

struct EvInit : public entityx::Event<EvInit>
{
   EvInit(int _levelNr, int _score)
   : levelNr(_levelNr)
   , score(_score)
   {
   }

   int levelNr;
   int score;
};

struct EvPauseGame : public entityx::Event<EvPauseGame>
{
   EvPauseGame() {}
};

struct EvResumeGame : public entityx::Event<EvResumeGame>
{
   EvResumeGame() {}
};

struct EvGameOver : public entityx::Event<EvGameOver>
{
   EvGameOver() {}
};

struct EvBossKilled : public entityx::Event<EvBossKilled>
{
   EvBossKilled() {}
};

struct EvPlaySound : public entityx::Event<EvPlaySound>
{
   EvPlaySound(SoundId _id)
   : id(_id)
   {
   }

   SoundId id;
};

struct EvMusicVolume : public entityx::Event<EvMusicVolume>
{
   EvMusicVolume(int _vol)
       :vol (_vol)
   {
   }
   int vol;
};

struct EvToggleFullscreen : public entityx::Event<EvToggleFullscreen>
{
   EvToggleFullscreen() {}
};

struct EvKeyboard : public entityx::Event<EvKeyboard>
{
   EvKeyboard(sf::Keyboard::Key _key, bool _isDown)
   : key(_key)
   , isDown(_isDown)
   {
   }

   sf::Keyboard::Key key;
   bool isDown;
};

struct EvReportScrollSpeed : public entityx::Event<EvReportScrollSpeed>
{
   EvReportScrollSpeed(double _scrollSpeed)
   : scrollSpeed(_scrollSpeed)
   {
   }

   double scrollSpeed;
};

struct EvReportSpaceShipId : public entityx::Event<EvReportSpaceShipId>
{
   EvReportSpaceShipId(entityx::Entity::Id _spaceShipId)
   : spaceShipId(_spaceShipId)
   {
   }

   entityx::Entity::Id spaceShipId;
};

struct EvCurrentScore : public entityx::Event<EvCurrentScore>
{
   EvCurrentScore(int _currentScore)
   : currentScore(_currentScore)
   {
   }

   int currentScore;
};

#endif // EVENTS_H
