#include "AudioManager.h"

AudioManager::AudioManager()
: m_soundMap()
, m_music()
{
}

void AudioManager::init()
{
   loadSoundEffect("../resources/gun_shoot.wav", GUN_SHOOT);
   loadSoundEffect("../resources/ship_explosion.wav", SHIP_EXPLOSION);
   loadSoundEffect("../resources/asteroid_hit.wav", ASTEROID_HIT);
   loadSoundEffect("../resources/asteroid_explosion.wav", ASTEROID_EXPLOSION);

   if (!m_music.openFromFile("../resources/Space_Fighter_Loop.ogg"))
       printf("Error loading music.");
}


void AudioManager::playSound(SoundId id)
{
   auto it = m_soundMap.find(id);

   if (it != end(m_soundMap))
   {
      // Is this how you'r supposed to do it? =/
      sf::Sound* pChannel;
      if(!m_channelOne.Playing)
      {
          pChannel = &m_channelOne;
      }
      else if(!m_channelTwo.Playing)
      {
          pChannel = &m_channelTwo;
      }
      else
      {
          pChannel = &m_channelOne;
      }

      pChannel->setBuffer(*it->second);
      pChannel->play();
   }
}

void AudioManager::playMusic()
{
    m_music.play();
}

void AudioManager::pauseMusic()
{
    if( m_music.Playing )
    {
        m_music.pause();
    }
    else
    {
        m_music.play();
    }
}

void AudioManager::loadSoundEffect(const std::string& fileName, SoundId id)
{
    m_soundMap[id] = new sf::SoundBuffer();
    if(!m_soundMap[id]->loadFromFile(fileName.c_str()))
        printf("Colud not load sound");
}
