#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <string>

#include <SFML/Audio.hpp>

#include "SoundId.h"

class AudioManager
{
public:

   AudioManager();

   void init();

   void playSound(SoundId id);

   void playMusic();

   void pauseMusic();

private:

   void loadSoundEffect(const std::string& fileName, SoundId id);

   void loadMusic(const std::string& fileName);

   typedef std::map<SoundId, sf::SoundBuffer*> SoundMap;

   SoundMap m_soundMap;

   sf::Sound m_channelOne;
   sf::Sound m_channelTwo;

   sf::Music m_music;
};

#endif // AUDIOMANAGER_H
